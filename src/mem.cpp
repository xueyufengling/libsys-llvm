#include <sys/llvm/mem.h>

#include <malloc.h>

#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/raw_ostream.h>

std::unique_ptr<::llvm::MemoryBuffer> sys::llvm::as_membuffer(const void* buf, size_t len, const char* name)
{
	return ::llvm::MemoryBuffer::getMemBuffer(::llvm::StringRef((const char*)buf, len), name, false);
}

c_array* sys::llvm::array_from_ostream(::llvm::raw_svector_ostream& os, size_t offset, size_t extra_len)
{
	::llvm::StringRef buf = os.str();
	size_t buf_size = buf.size();
	c_array* arr = alloc_c_array(buf_size + extra_len);
	memcpy(arr->data + offset, buf.data(), buf_size);
	return arr;
}
