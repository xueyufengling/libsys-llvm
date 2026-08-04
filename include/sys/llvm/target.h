#ifndef _SYS_LLVM_TARGET
#define _SYS_LLVM_TARGET

#include <ppmp/semantic.h>
#include <ppmp/list_op.h>

namespace sys
{
namespace llvm
{
#if !defined(__llvm_support_target_list_rm_expand_id1__)
#define __llvm_support_target_list_rm_expand_id1__() 0
#endif

#if !defined(__llvm_support_target_list_rm_expand_id2__)
#define __llvm_support_target_list_rm_expand_id2__() 1
#endif

// __equal__()辅助宏
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
#define __equal_def__ARC(x) x
#define __equal_def__CSKY(x) x
#define __equal_def__DirectX(x) x
#define __equal_def__M68k(x) x
#define __equal_def__Xtensa(x) x

/**
 * @brief LLVM支持的全部架构（包含实验支持架构），参考llvm/CMakeLists.txt中的LLVM_ALL_TARGETS和LLVM_ALL_EXPERIMENTAL_TARGETS
 */
#define __llvm_support_target_list__() AArch64, AMDGPU, ARM, AVR, BPF, Hexagon, Lanai, LoongArch, Mips, MSP430, NVPTX, PowerPC, RISCV, Sparc, SPIRV, SystemZ, VE, WebAssembly, X86, XCore, ARC, CSKY, DirectX, M68k, Xtensa

#define __llvm_support_target_list_rm__(...)\
	__list_rm_eq__(__llvm_support_target_list_rm_expand_id1__(), __llvm_support_target_list_rm_expand_id2__(),\
			__pack_list__(__VA_ARGS__), __llvm_support_target_list__())

/**
 * @brief 目标架构枚举
 */
__enum_def__(0, llvm_target, , __llvm_support_target_list__())

/**
 * @brief 必须CMake编译才有的宏定义，判断当前安装的LLVM build是否编译打包了指定架构的库函数
 */
#define __llvm_build_target__(target) __cat__(3, __llvm_build_target_, target, __)
}
}

#endif//_SYS_LLVM_TARGET
