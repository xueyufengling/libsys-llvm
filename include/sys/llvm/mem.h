#ifndef _SYS_LLVM_MEM
#define _SYS_LLVM_MEM

#include <memory>

#include <arch/c_array.h>

#include <llvm/ADT/SmallString.h>

namespace llvm
{
class MemoryBuffer;
class raw_svector_ostream;
}

namespace sys
{
namespace llvm
{
constexpr size_t default_stack_buffer_size = 4096;

typedef ::llvm::SmallString<default_stack_buffer_size> stack_buffer;

extern std::unique_ptr<::llvm::MemoryBuffer> as_membuffer(const void* buf, size_t len, const char* name = "");

/**
 * @brief 将array内存包装成LLVM的MemoryBuffer
 */
inline std::unique_ptr<::llvm::MemoryBuffer> as_membuffer(c_array* arr_ptr)
{
	return as_membuffer(arr_ptr->data, arr_ptr->size);
}

extern c_array* array_from_ostream(::llvm::raw_svector_ostream& os, size_t offset = 0, size_t extra_len = 0);
}
}

#endif //_SYS_LLVM_MEM
