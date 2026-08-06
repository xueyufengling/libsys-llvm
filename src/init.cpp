#include <sys/llvm/init.h>

#include <sys/llvm/target_func.h>

using namespace sys::llvm;

init_as_state sys::llvm::init_as(llvm_target target)
{
	int ret = init_as_state::init_as_state_all_success;
	// 不需要短路运算
	if(!initialize_target_info(target) | !initialize_target_mc(target))
		ret |= init_as_state::init_as_state_target_failed;
	if(!initialize_asm_parser(target))
		ret |= init_as_state::init_as_state_asm_failed;
	if(!initialize_disassembler(target))
		ret |= init_as_state::init_as_state_disasm_failed;
	return (init_as_state)ret;
}
