#include "vpad.h"
#include "vpad_core.h"

namespace vpad
{

void
VPADInit()
{
}

void
VPADSetAccParam(uint32_t chan, float unk1, float unk2)
{
}

void
VPADSetBtnRepeat(uint32_t chan, float unk1, float unk2)
{
}

void
Module::registerCoreFunctions()
{
   RegisterKernelFunction(VPADInit);
   RegisterKernelFunction(VPADSetAccParam);
   RegisterKernelFunction(VPADSetBtnRepeat);
}

} // namespace vpad
