#include <sys/llvm/init.h>

#include <sys/llvm/target_func.h>

using namespace sys::llvm;

bool sys::llvm::init_target(llvm_target target)
{
	bool ret = true;
	ret &= !initialize_target_info(target);
	ret &= !initialize_target(target);
	ret &= !initialize_target_mc(target);
	return ret;
}

bool sys::llvm::init_asm(llvm_target target)
{
	return !initialize_asm_parser(target);
}

bool sys::llvm::init_disasm(llvm_target target)
{
	bool ret = true;
	ret &= !initialize_disassembler(target);
	ret &= !initialize_asm_printer(target);
	return ret;
}
