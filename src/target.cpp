#include <sys/llvm/target.h>

#include <llvm/Config/llvm-config.h>

using namespace sys::llvm;

const llvm_target sys::llvm::host_llvm_target = __llvm_target_enum__(LLVM_NATIVE_ARCH);
