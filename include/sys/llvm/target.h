#ifndef _SYS_LLVM_TARGET
#define _SYS_LLVM_TARGET

#include <ppmp/semantic.h>
#include <ppmp/list_op.h>

#include "target_list.h"

namespace sys
{
namespace llvm
{
#if !defined(__llvm_all_support_target_list_rm_expand_id1__)
#define __llvm_all_support_target_list_rm_expand_id1__() 0
#endif

#if !defined(__llvm_all_support_target_list_rm_expand_id2__)
#define __llvm_all_support_target_list_rm_expand_id2__() 1
#endif

/**
 * @brief LLVM支持的全部架构（包含实验支持架构），参考llvm/CMakeLists.txt中的LLVM_ALL_TARGETS和LLVM_ALL_EXPERIMENTAL_TARGETS
 */

#define __llvm_all_support_target_list_rm__(...)\
	__list_rm_eq__(__llvm_all_support_target_list_rm_expand_id1__(), __llvm_all_support_target_list_rm_expand_id2__(),\
			__pack_list__(__VA_ARGS__), __llvm_all_support_target_list__())

/**
 * @brief 所有LLVM支持的目标架构枚举
 */
__enum_def__(0, llvm_target, , __llvm_all_support_target_list__())

#define __llvm_target_enum__(target) (::sys::llvm::llvm_target::__enum_def_elem__(llvm_target, target))

extern const llvm_target host_llvm_target;

/**
 * @brief 必须CMake编译才有的宏定义，判断当前安装的LLVM build是否编译打包了指定架构的库函数
 */
#define __llvm_enable_target__(target) __cat__(3, __llvm_enable_target_, target, __)
}
}

#endif//_SYS_LLVM_TARGET
