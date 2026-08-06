#ifndef __SYS_LLVM_TARGETLIST
#define __SYS_LLVM_TARGETLIST

#include <ppmp/equal.h>

#define __llvm_support_target_list__() AArch64, AMDGPU, ARM, AVR, BPF, Hexagon, Lanai, LoongArch, Mips, MSP430, NVPTX, PowerPC, RISCV, Sparc, SPIRV, SystemZ, VE, WebAssembly, X86, XCore

#define __llvm_build_target_AArch64__() 1
#define __equal_def__AArch64(x) x

#define __llvm_build_target_AMDGPU__() 1
#define __equal_def__AMDGPU(x) x

#define __llvm_build_target_ARM__() 1
#define __equal_def__ARM(x) x

#define __llvm_build_target_AVR__() 1
#define __equal_def__AVR(x) x

#define __llvm_build_target_BPF__() 1
#define __equal_def__BPF(x) x

#define __llvm_build_target_Hexagon__() 1
#define __equal_def__Hexagon(x) x

#define __llvm_build_target_Lanai__() 1
#define __equal_def__Lanai(x) x

#define __llvm_build_target_LoongArch__() 1
#define __equal_def__LoongArch(x) x

#define __llvm_build_target_Mips__() 1
#define __equal_def__Mips(x) x

#define __llvm_build_target_MSP430__() 1
#define __equal_def__MSP430(x) x

#define __llvm_build_target_NVPTX__() 1
#define __equal_def__NVPTX(x) x

#define __llvm_build_target_PowerPC__() 1
#define __equal_def__PowerPC(x) x

#define __llvm_build_target_RISCV__() 1
#define __equal_def__RISCV(x) x

#define __llvm_build_target_Sparc__() 1
#define __equal_def__Sparc(x) x

#define __llvm_build_target_SPIRV__() 1
#define __equal_def__SPIRV(x) x

#define __llvm_build_target_SystemZ__() 1
#define __equal_def__SystemZ(x) x

#define __llvm_build_target_VE__() 1
#define __equal_def__VE(x) x

#define __llvm_build_target_WebAssembly__() 1
#define __equal_def__WebAssembly(x) x

#define __llvm_build_target_X86__() 1
#define __equal_def__X86(x) x

#define __llvm_build_target_XCore__() 1
#define __equal_def__XCore(x) x

#endif// __SYS_LLVM_TARGETLIST
