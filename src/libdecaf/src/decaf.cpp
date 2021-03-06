#include "common/platform_dir.h"
#include "decaf.h"
#include "decaf_config.h"
#include "decaf_graphics.h"
#include "decaf_input.h"
#include "decaf_sound.h"
#include "debugger/debugger.h"
#include "debugger/debugger_ui.h"
#include "filesystem/filesystem.h"
#include "input/input.h"
#include "kernel/kernel.h"
#include "kernel/kernel_hlefunction.h"
#include "kernel/kernel_filesystem.h"
#include "libcpu/cpu.h"
#include "libcpu/mem.h"
#include "modules/coreinit/coreinit_fs.h"
#include "modules/coreinit/coreinit_scheduler.h"
#include <condition_variable>
#include <mutex>

namespace decaf
{

class LogFormatter : public spdlog::formatter
{
public:
   void format(spdlog::details::log_msg& msg) override
   {
      auto tm_time = spdlog::details::os::localtime(spdlog::log_clock::to_time_t(msg.time));
      auto duration = msg.time.time_since_epoch();
      auto micros = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 1000000;

      msg.formatted << '[' << fmt::pad(static_cast<unsigned int>(tm_time.tm_min), 2, '0') << ':'
         << fmt::pad(static_cast<unsigned int>(tm_time.tm_sec), 2, '0') << '.'
         << fmt::pad(static_cast<unsigned int>(micros), 6, '0');

      msg.formatted << ' ';

      msg.formatted << spdlog::level::to_str(msg.level);

      msg.formatted << ':';

      auto core = cpu::this_core::state();
      if (core) {
         auto thread = coreinit::internal::getCurrentThread();
         if (thread) {
            msg.formatted.write("w{:01X}{:02X}", core->id, static_cast<uint16_t>(thread->id));
         } else {
            msg.formatted.write("w{:01X}{:02X}", core->id, 0xFF);
         }
      } else {
         msg.formatted << msg.thread_id;
      }

      msg.formatted << "] ";

      msg.formatted << fmt::StringRef(msg.raw.data(), msg.raw.size());
      msg.formatted.write(spdlog::details::os::eol, spdlog::details::os::eol_size);
   }
};

std::string
makeConfigPath(const std::string &filename)
{
   return fs::HostPath { platform::getConfigDirectory() }
      .join("decaf")
      .join(filename)
      .path();
}

bool
createConfigDirectory()
{
   return platform::createParentDirectories(makeConfigPath("."));
}

void
initialiseLogging(std::vector<spdlog::sink_ptr> &sinks,
                  spdlog::level::level_enum level)
{
   gLog = std::make_shared<spdlog::logger>("decaf", begin(sinks), end(sinks));
   gLog->set_level(level);
   gLog->set_formatter(std::make_shared<LogFormatter>());
}

bool
initialise(const std::string &gamePath)
{
   if (!getInputDriver()) {
      gLog->error("No input driver set");
      return false;
   }

   if (!getGraphicsDriver()) {
      gLog->error("No graphics driver set");
      return false;
   }

   // Set JIT mode
   if (decaf::config::jit::enabled) {
      if (!decaf::config::jit::debug) {
         cpu::setJitMode(cpu::jit_mode::enabled);
      } else {
         cpu::setJitMode(cpu::jit_mode::debug);
      }
   } else {
      cpu::setJitMode(cpu::jit_mode::disabled);
   }

   // Setup core
   mem::initialise();
   cpu::initialise();
   kernel::initialise();

   // Setup filesystem
   auto filesystem = new fs::FileSystem();

   // Find a valid application to run
   auto path = fs::HostPath { gamePath };
   auto volPath = fs::HostPath { };
   auto rpxPath = fs::HostPath { };

   if (platform::isDirectory(path.path())) {
      if (platform::isFile(path.join("code").join("cos.xml").path())) {
         // Found path/code/cos.xml
         volPath = path.path();
      } else if (platform::isFile(path.join("data").join("code").join("cos.xml").path())) {
         // Found path/data/code/cos.xml
         volPath = path.join("data").path();
      }
   } else if (platform::isFile(path.path())) {
      auto parent1 = fs::HostPath { path.parentPath() };
      auto parent2 = fs::HostPath { parent1.parentPath() };

      if (platform::isFile(parent2.join("code").join("cos.xml").path())) {
         // Found file/../code/cos.xml
         volPath = parent2.path();
      } else if (path.extension().compare("rpx") == 0) {
         // Found file.rpx
         rpxPath = path.path();
      }
   }

   if (!volPath.path().empty()) {
      gLog->debug("Mount {} to /vol", volPath.path());
      filesystem->mountHostFolder("/vol", volPath.path());
   } else if (!rpxPath.path().empty()) {
      gLog->debug("Mount {} to /vol/code/{}", rpxPath.path(), rpxPath.filename());
      filesystem->mountHostFile("/vol/code/" + rpxPath.filename(), rpxPath.path());
      kernel::setExecutableFilename(rpxPath.filename());
   } else {
      gLog->error("Could not find valid application at {}", path.path());
      return false;
   }

   // Setup kernel
   kernel::setFileSystem(filesystem);

   // Mount system path
   auto systemPath = fs::HostPath { decaf::config::system::system_path };
   filesystem->mountHostFolder("/vol/storage_mlc01", systemPath.join("mlc"));

   // Startup the filesystem thread
   coreinit::internal::startFsThread();

   return true;
}

void
start()
{
   cpu::start();

   volatile int zero = 0;
   if (zero) {
      tracePrint(nullptr, 0, 0);
      traceReg(nullptr, 0, 0);
      traceRegStart(nullptr, 0, 0);
      traceRegNext(0);
      traceRegContinue();
   }
}

bool
hasExited()
{
   return kernel::hasExited();
}

int
waitForExit()
{
   // Wait for CPU to finish
   cpu::join();

   // Make sure we clean up
   decaf::shutdown();

   return kernel::getExitCode();
}

void
shutdown()
{
   // Make sure the CPU stops being blocked by the debugger.
   if (::debugger::paused()) {
      // TODO: This is technically a race as the debugger is designed such that
      //  it controls when the cores resume.  This might need to be routed through
      //  debugger::ui for that reason.
      ::debugger::resumeAll();
   }

   // Shut down CPU
   cpu::halt();

   // Wait for CPU to finish
   cpu::join();

   // Stop the FS
   coreinit::internal::shutdownFsThread();

   // Stop graphics driver
   auto graphicsDriver = getGraphicsDriver();

   if (graphicsDriver) {
      graphicsDriver->stop();
   }

   setGraphicsDriver(nullptr);

   // Stop sound driver
   auto soundDriver = getSoundDriver();

   if (soundDriver) {
      soundDriver->stop();
   }

   setSoundDriver(nullptr);
}

void
injectMouseButtonInput(input::MouseButton button,
                       input::MouseAction action)
{
   ::debugger::ui::injectMouseButtonInput(button, action);
}

void
injectMousePos(float x,
               float y)
{
   ::debugger::ui::injectMousePos(x, y);
}

void
injectScrollInput(float xoffset,
                  float yoffset)
{
   ::debugger::ui::injectScrollInput(xoffset, yoffset);
}

void
injectKeyInput(input::KeyboardKey key,
               input::KeyboardAction action)
{
   ::debugger::ui::injectKeyInput(key, action);
}

void
injectTextInput(const char *text)
{
   ::debugger::ui::injectTextInput(text);
}

void
setClipboardTextCallbacks(ClipboardTextGetCallback getter,
                          ClipboardTextSetCallback setter)
{
   ::debugger::ui::setClipboardTextCallbacks(getter, setter);
}

} // namespace decaf
