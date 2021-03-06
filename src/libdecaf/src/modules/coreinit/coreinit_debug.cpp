#include "coreinit.h"
#include "coreinit_debug.h"
#include "coreinit_exit.h"
#include "coreinit_thread.h"
#include "kernel/kernel_loader.h"
#include "libcpu/trace.h"
#include "common/log.h"
#include "common/make_array.h"
#include "common/strutils.h"
#include <sstream>

namespace coreinit
{

static std::stringstream
sOSConsoleWriteBuffer;

BOOL
OSIsDebuggerPresent()
{
   return FALSE;
}

BOOL
OSIsDebuggerInitialized()
{
   return FALSE;
}

static const auto c_flags = make_array<char>(
   '-', '+', ' ', '#', '0'
);

static const auto c_width = make_array<char>(
   '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*'
);

static const auto c_precision = make_array<char>(
   '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*'
);

static const auto c_length = make_array<char>(
   'h', 'l', 'j', 'z', 't', 'L'
);

static const auto c_specifier = make_array<char>(
   'd', 'i', 'u', 'o', 'x', 'X', 'f', 'F', 'e',
   'E', 'g', 'G', 'a', 'A', 'c', 's', 'p', 'n'
);

static void
formatString(const char *fmt, ppctypes::VarList &args, std::string &output)
{
   output.reserve(strlen(fmt));

   for (auto i = 0; i < strlen(fmt); ) {
      if (fmt[i] == '%') {
         i++;

         if (fmt[i] == '%') {
            output.push_back('%');
            ++i;
            continue;
         }

         std::string flags, width, length, precision, formatter;
         char specifier = 0;

         while (std::find(c_flags.begin(), c_flags.end(), fmt[i]) != c_flags.end()) {
            flags.push_back(fmt[i]);
            ++i;
         }

         while (std::find(c_width.begin(), c_width.end(), fmt[i]) != c_width.end()) {
            width.push_back(fmt[i]);
            ++i;
         }

         if (fmt[i] == '.') {
            while (std::find(c_precision.begin(), c_precision.end(), fmt[i]) != c_precision.end()) {
               precision.push_back(fmt[i]);
               ++i;
            }
         }

         while (std::find(c_length.begin(), c_length.end(), fmt[i]) != c_length.end()) {
            length.push_back(fmt[i]);
            ++i;
         }

         if (std::find(c_specifier.begin(), c_specifier.end(), fmt[i]) != c_specifier.end()) {
            specifier = fmt[i];
            ++i;
         }

         switch (specifier) {
         case 'd':
         case 'i':
         case 'u':
         case 'o':
         case 'x':
         case 'X':
         case 'c':
            formatter = "%" + flags + width + precision + length + specifier;
            if (length.compare("ll") == 0 && specifier != 'c') {
               output.append(format_string(formatter.c_str(), args.next<uint64_t>()));
            } else {
               output.append(format_string(formatter.c_str(), args.next<uint32_t>()));
            }
            break;
         case 'g':
         case 'G':
         case 'f':
         case 'F':
         case 'e':
         case 'E':
         case 'a':
         case 'A':
            formatter = "%" + flags + width + precision + length + specifier;
            if (length.compare("L") == 0) {
               output.append(format_string(formatter.c_str(), static_cast<long double>(args.next<double>())));
            } else {
               output.append(format_string(formatter.c_str(), args.next<double>()));
            }
            break;
         case 'p':
            formatter = "%" + flags + width + precision + length + specifier;
            output.append(format_string(formatter.c_str(), bit_cast<void *, uintptr_t>(mem::untranslate(args.next<void *>()))));
            break;
         case 's':
            output.append(args.next<const char *>());
            break;
         case 'n':
            if (length.compare("hh") == 0) {
               *(args.next<int8_t *>()) = static_cast<int8_t>(output.size());
            } else if (length.compare("h") == 0) {
               *(args.next<be_val<int16_t> *>()) = static_cast<int16_t>(output.size());
            } else if (length.compare("ll") == 0) {
               *(args.next<be_val<int64_t> *>()) = static_cast<int64_t>(output.size());
            } else {
               *(args.next<be_val<int32_t> *>()) = static_cast<int32_t>(output.size());
            }
            break;
         default:
            gLog->error("Unimplemented format specifier: {}", specifier);
            break;
         }
      } else {
         output.push_back(fmt[i]);
         ++i;
      }
   }
}

static void
OSPanic(const char *file,
        int line,
        const char *fmt,
        ppctypes::VarList &args)
{
   std::string str;
   formatString(fmt, args, str);
   gLog->error("[OSPanic] {}:{} {}", file, line, str);
   ghs_exit(-1);
}

static void
OSReport(const char *fmt,
         ppctypes::VarList &args)
{
   std::string str;
   formatString(fmt, args, str);
   gLog->info("[OSReport] {}", str);
}

static void
OSVReport(const char *fmt,
          ppctypes::VarList &args)
{
   std::string str;
   formatString(fmt, args, str);
   gLog->info("[OSVReport] {}", str);
}

static void
COSWarn(uint32_t module,
        const char *fmt,
        ppctypes::VarList &args)
{
   std::string str;
   formatString(fmt, args, str);
   gLog->info("[COSWarn] {} {}", module, str);
}

static void
OSConsoleWrite(const char *msg,
               uint32_t size)
{
   auto str = std::string { msg, size };
   gLog->info("[OSConsoleWrite] {}", str);

   for (uint32_t i = 0; i < size; ++i) {
      if (msg[i] == '\n') {
         gLog->info("[CONSOLE OUTPUT] {}", sOSConsoleWriteBuffer.str());
         sOSConsoleWriteBuffer.clear();
         continue;
      }

      sOSConsoleWriteBuffer.put(msg[i]);
   }
}

static int
coreinit__os_snprintf(char *buffer,
                      uint32_t size,
                      const char *fmt,
                      ppctypes::VarList &args)
{
   std::string str;
   formatString(fmt, args, str);
   return snprintf(buffer, size, "%s", str.c_str());
}

static uint32_t
OSGetSymbolName(uint32_t address,
                char *buffer,
                int bufsize)
{
   auto retval = 0u;
   auto found = false;

   kernel::loader::lockLoader();
   const auto &modules = kernel::loader::getLoadedModules();

   for (auto &mod : modules) {
      auto codeBase = 0u;

      for (auto &sec : mod.second->sections) {
         if (sec.name.compare(".text") == 0) {
            codeBase = sec.start;
            break;
         }
      }

      for (auto &sym : mod.second->symbols) {
         if (sym.second.address == address) {
            strncpy(buffer, sym.first.c_str(), bufsize);
            retval = codeBase;
            found = true;
            break;
         }
      }

      if (found) {
         break;
      }
   }

   kernel::loader::unlockLoader();
   return retval;
}

void
Module::registerDebugFunctions()
{
   RegisterKernelFunction(OSIsDebuggerPresent);
   RegisterKernelFunction(OSIsDebuggerInitialized);
   RegisterKernelFunction(OSPanic);
   RegisterKernelFunction(OSReport);
   RegisterKernelFunction(OSVReport);
   RegisterKernelFunction(COSWarn);
   RegisterKernelFunction(OSConsoleWrite);
   RegisterKernelFunctionName("__os_snprintf", coreinit__os_snprintf);
   RegisterKernelFunction(OSGetSymbolName);
}

} // namespace coreinit
