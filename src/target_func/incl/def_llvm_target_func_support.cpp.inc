case ::sys::llvm::llvm_target::__cat__(2, llvm_target_, __llvm_target_arch__()):
{
#if __list_contains__(__def_llvm_target_func_expand_id__(), __llvm_target_arch__(), __llvm_target_func_arch_list__())
	__if_intl__(__not_equal__(__llvm_target_func_ret_type__(), void))
	(
		if(ret)
			*ret = __cat__(3, __llvm_target_func_prefix__(), __llvm_target_arch__(), __llvm_target_func_suffix__())(__llvm_target_func_args_name_list__());
		else
	)
			__cat__(3, __llvm_target_func_prefix__(), __llvm_target_arch__(), __llvm_target_func_suffix__())(__llvm_target_func_args_name_list__());
	return ::sys::llvm::llvm_fcall_state::llvm_fcall_state_success;
#else
	return ::sys::llvm::llvm_fcall_state::llvm_fcall_state_func_unsupport;
#endif
}
#undef __llvm_target_arch__
