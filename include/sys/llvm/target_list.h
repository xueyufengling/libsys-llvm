#ifndef __SYS_LLVM_TARGETLIST
#define __SYS_LLVM_TARGETLIST

#include <ppmp/equal.h>

#define __llvm_all_support_target_list__() AArch64, AMDGPU, ARM, AVR, BPF, Hexagon, Lanai, LoongArch, Mips, MSP430, NVPTX, PowerPC, RISCV, Sparc, SPIRV, SystemZ, VE, WebAssembly, X86, XCore

#define __equal_def__AArch64(x) x
#define __equal_def__AMDGPU(x) x
#define __equal_def__ARM(x) x
#define __equal_def__AVR(x) x
#define __equal_def__BPF(x) x
#define __equal_def__Hexagon(x) x
#define __equal_def__Lanai(x) x
#define __equal_def__LoongArch(x) x
#define __equal_def__Mips(x) x
#define __equal_def__MSP430(x) x
#define __equal_def__NVPTX(x) x
#define __equal_def__PowerPC(x) x
#define __equal_def__RISCV(x) x
#define __equal_def__Sparc(x) x
#define __equal_def__SPIRV(x) x
#define __equal_def__SystemZ(x) x
#define __equal_def__VE(x) x
#define __equal_def__WebAssembly(x) x
#define __equal_def__X86(x) x
#define __equal_def__XCore(x) x
#define __llvm_enable_target_X86__() 1

#endif// _SYS_LLVM_TARGETLIST
