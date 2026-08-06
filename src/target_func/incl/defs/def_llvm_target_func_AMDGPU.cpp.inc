#define __llvm_target_arch__() AMDGPU
#if defined(__llvm_enable_target_AMDGPU__)
#include "target_func/incl/def_llvm_target_func_support.cpp.inc"
#else
#include "target_func/incl/def_llvm_target_func_unsupport.cpp.inc"
#endif