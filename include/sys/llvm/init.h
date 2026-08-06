#ifndef _SYS_LLVM_INIT
#define _SYS_LLVM_INIT

#include <arch/bit_flag.h>

#include "target.h"

namespace sys
{
namespace llvm
{
enum init_as_state : int
{
	init_as_state_all_success = 0,
	init_as_state_target_failed = arch::bit_flag<int>(0),
	init_as_state_asm_failed = arch::bit_flag<int>(1),
	init_as_state_disasm_failed = arch::bit_flag<int>(2)
};

/**
 * @brief 初始化汇编器、反汇编器
 */
extern init_as_state init_as(llvm_target target = sys::llvm::host_llvm_target);
}
}

#endif//_SYS_LLVM_INIT
