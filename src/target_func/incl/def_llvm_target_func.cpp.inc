#if !defined(__def_llvm_target_func_expand_id__)
#define __def_llvm_target_func_expand_id__() 5
#endif

#define __llvm_target_func_ret_type__() __llvm_target_func_info_ret_type__(__def_llvm_target_func_info__())
#define __llvm_target_func_prefix__() __llvm_target_func_info_prefix__(__def_llvm_target_func_info__())
#define __llvm_target_func_suffix__() __llvm_target_func_info_suffix__(__def_llvm_target_func_info__())
#define __llvm_target_func_export_name__() __llvm_target_func_info_export_name__(__def_llvm_target_func_info__())
#define __llvm_target_func_arch_list__() __llvm_target_func_info_arch_list__(__def_llvm_target_func_info__())
#define __llvm_target_func_args_list__() __llvm_target_func_info_args_list__(__def_llvm_target_func_info__())
#define __llvm_target_func_args_decl_list__() __llvm_target_func_info_args_decl_list__(__def_llvm_target_func_info__())
#define __llvm_target_func_args_name_list__() __llvm_target_func_info_args_name_list__(__def_llvm_target_func_info__())

__decl_llvm_target_func_signature__(__llvm_target_func_ret_type__(), sys::llvm::__llvm_target_func_export_name__(), __llvm_target_func_args_decl_list__())
{
	switch(target)
	{
#include "target_func/incl/defs/def_llvm_target_func_dispatch_all.cpp.inc"
		default:
		{
			return ::sys::llvm::llvm_fcall_state::llvm_fcall_state_arch_invalid;
		}
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
