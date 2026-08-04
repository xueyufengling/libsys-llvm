case ::sys::llvm::llvm_target::__cat__(2, llvm_target_, __llvm_target_arch__()):
{
#if __list_contains__(__def_llvm_target_func_expand_id__(), __llvm_target_arch__(), __llvm_target_func_arch_list__())
	__cat__(3, __llvm_target_func_prefix__(), __llvm_target_arch__(), __llvm_target_func_suffix__())(__llvm_target_func_args_name_list__());
#else
	::llvm::errs() << "llvm function '" __str__(__llvm_target_func_export_name__()) "' unsupport target type '" __str__(__llvm_target_arch__()) "'\n";
#endif
}
#undef __llvm_target_arch__
