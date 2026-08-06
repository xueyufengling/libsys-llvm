#ifndef _SYS_LLVM_INIT
#define _SYS_LLVM_INIT

#include "target.h"

namespace sys
{
namespace llvm
{
/**
 * @brief 基本的初始化，必须调用
 */
extern bool init_target(llvm_target target = sys::llvm::native_llvm_target);

/**
 * @brief 初始化汇编器
 */
extern bool init_asm(llvm_target target = sys::llvm::native_llvm_target);

/**
 * @brief 初始化反汇编器
 */
extern bool init_disasm(llvm_target target = sys::llvm::native_llvm_target);
}
}

#endif//_SYS_LLVM_INIT
