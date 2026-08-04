#include <sys/llvm/target_func.h>

#include <llvm/Support/TargetSelect.h>

#define __def_llvm_target_func_info__() __at_exp__(1, __llvm_target_func_info_list__())

#include "target_func/incl/def_llvm_target_func.cpp.inc"

#undef __def_llvm_target_func_info__
