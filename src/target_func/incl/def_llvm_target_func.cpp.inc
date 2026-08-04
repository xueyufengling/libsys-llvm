#include <llvm/Support/raw_ostream.h>

#include <sys/llvm/target_func.h>

#if !defined(__def_llvm_target_func_expand_id__)
#define __def_llvm_target_func_expand_id__() 0
#endif

#define __llvm_target_func_ret_type__() __llvm_target_func_info_ret_type__(__def_llvm_target_func_info__())
#define __llvm_target_func_prefix__() __llvm_target_func_info_prefix__(__def_llvm_target_func_info__())
#define __llvm_target_func_suffix__() __llvm_target_func_info_suffix__(__def_llvm_target_func_info__())
#define __llvm_target_func_export_name__() __llvm_target_func_info_export_name__(__def_llvm_target_func_info__())
#define __llvm_target_func_arch_list__() __llvm_target_func_info_arch_list__(__def_llvm_target_func_info__())
#define __llvm_target_func_args_list__() __llvm_target_func_info_args_list__(__def_llvm_target_func_info__())
#define __llvm_target_func_args_decl_list__() __declaration_list__(__def_llvm_target_func_expand_id__(), __llvm_target_func_args_list__())
#define __llvm_target_func_args_name_list__() __declaration_name_list__(__def_llvm_target_func_expand_id__(), __llvm_target_func_args_list__())

__llvm_target_func_ret_type__() ::sys::llvm::__llvm_target_func_export_name__()(::sys::llvm::llvm_target target
		__va_opt_comma__(__llvm_target_func_args_list__()) __llvm_target_func_args_decl_list__())
{
	switch (target)
	{
#if defined(__llvm_build_target_AArch64__)
#define __llvm_target_arch__() AArch64
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_AMDGPU__)
#define __llvm_target_arch__() AMDGPU
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_ARM__)
#define __llvm_target_arch__() ARM
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_AVR__)
#define __llvm_target_arch__() AVR
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_BPF__)
#define __llvm_target_arch__() BPF
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_Hexagon__)
#define __llvm_target_arch__() Hexagon
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_Lanai__)
#define __llvm_target_arch__() Lanai
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_LoongArch__)
#define __llvm_target_arch__() LoongArch
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_Mips__)
#define __llvm_target_arch__() Mips
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_MSP430__)
#define __llvm_target_arch__() MSP430
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_NVPTX__)
#define __llvm_target_arch__() NVPTX
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_PowerPC__)
#define __llvm_target_arch__() PowerPC
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_RISCV__)
#define __llvm_target_arch__() RISCV
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_Sparc__)
#define __llvm_target_arch__() Sparc
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_SPIRV__)
#define __llvm_target_arch__() SPIRV
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_SystemZ__)
#define __llvm_target_arch__() SystemZ
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_VE__)
#define __llvm_target_arch__() VE
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_WebAssembly__)
#define __llvm_target_arch__() WebAssembly
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_X86__)
#define __llvm_target_arch__() X86
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_XCore__)
#define __llvm_target_arch__() XCore
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_ARC__)
#define __llvm_target_arch__() ARC
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_CSKY__)
#define __llvm_target_arch__() CSKY
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_DirectX__)
#define __llvm_target_arch__() DirectX
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_M68k__)
#define __llvm_target_arch__() M68k
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
#if defined(__llvm_build_target_Xtensa__)
#define __llvm_target_arch__() Xtensa
#include "target_func/incl/def_llvm_target_func_case.cpp.inc"
#endif
		break;
		default:
		::llvm::errs() << "llvm function '" __str__(__llvm_target_func_export_name__()) "' unsupport target type '" << (target) << "'\n";
		break;
	}
}

#undef __llvm_target_func_ret_type__
#undef __llvm_target_func_prefix__
#undef __llvm_target_func_suffix__
#undef __llvm_target_func_export_name__
#undef __llvm_target_func_arch_list__
#undef __llvm_target_func_args_list__
#undef __llvm_target_func_args_decl_list__
#undef __llvm_target_func_args_name_list__
