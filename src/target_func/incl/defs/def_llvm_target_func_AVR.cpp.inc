#define __llvm_target_arch__() AVR
#if defined(__llvm_enable_target_AVR__)
#include "target_func/incl/def_llvm_target_func_support.cpp.inc"
#else
#include "target_func/incl/def_llvm_target_func_unsupport.cpp.inc"
#endif