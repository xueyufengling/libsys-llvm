#define __llvm_target_arch__() Hexagon
#if defined(__llvm_build_target_Hexagon__)
#include "target_func/incl/def_llvm_target_func_support.cpp.inc"
#else
#include "target_func/incl/def_llvm_target_func_unsupport.cpp.inc"
#endif