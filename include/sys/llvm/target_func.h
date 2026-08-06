#ifndef _SYS_LLVM_TARGETFUNC
#define _SYS_LLVM_TARGETFUNC

#include <ppmp/linguistic.h>

#include "target.h"

/**
 * 使用枚举值分发LLVM函数名中带架构名称的函数
 */

namespace sys
{
namespace llvm
{
#if !defined(__decl_llvm_target_func_expand_id__)
#define __decl_llvm_target_func_expand_id__() 2
#endif

#if !defined(__decl_llvm_target_func_decl_list_expand_id__)
#define __decl_llvm_target_func_decl_list_expand_id__() 3
#endif

#if !defined(__decl_llvm_target_func_decl_name_list_expand_id__)
#define __decl_llvm_target_func_decl_name_list_expand_id__() 4
#endif

/**
 * @brief 包装函数名带架构名称的函数信息。由于LLVM构建的包中不一定包含所有架构，若不包含架构X，那么编译时名字含X的函数就不存在，会编译错误。
 * 		  此宏的目的在于包装原函数，即便LLVM build中不包含目标架构，也不会报错。包装函数依赖CMake脚本设置宏告知build含有哪些架构，必须使用CMake编译。
 * @param ret_type LLVM原函数返回值类型
 * @param prefix LLVM原函数名前缀，即架构名之前的名称部分
 * @param suffix LLVM原函数名后缀，即架构名之后的名称部分
 * @param export_name 对外导出的包装函数名
 * @param arch_list 支持该函数的架构列表
 * @param ... 原函数的参数列表，使用__declaration__()声明，没有则留空
 */
#define __llvm_target_func_info__(ret_type, prefix, suffix, export_name, arch_list, ...)\
	__pack__(ret_type, prefix, suffix, export_name, __pack__(arch_list), __pack__(__VA_ARGS__))

#define __llvm_target_func_info_ret_type__(info)\
	__at_exp__(0, __unpack__(info))

#define __llvm_target_func_info_prefix__(info)\
	__at_exp__(1, __unpack__(info))

#define __llvm_target_func_info_suffix__(info)\
	__at_exp__(2, __unpack__(info))

#define __llvm_target_func_info_export_name__(info)\
	__at_exp__(3, __unpack__(info))

#define __llvm_target_func_info_arch_list__(info)\
	__unpack__(__at_exp__(4, __unpack__(info)))

#define __llvm_target_func_info_args_list__(info)\
	__unpack__(__at_exp__(5, __unpack__(info)))

#define __llvm_target_func_info_args_decl_list__(info)\
	__declaration_list__(__decl_llvm_target_func_decl_name_list_expand_id__(), __llvm_target_func_info_args_list__(info))

#define __llvm_target_func_info_args_name_list__(info)\
	__declaration_name_list__(__decl_llvm_target_func_decl_name_list_expand_id__(), __llvm_target_func_info_args_list__(info))

#define __llvm_disassembler_support_target_list__() __llvm_support_target_list_rm__(NVPTX, SPIRV)

#define __llvm_asm_parser_support_target_list__() __llvm_support_target_list_rm__(NVPTX, SPIRV, XCore)

/**
 * @brief LLVM封装函数的执行结果
 */
enum llvm_fcall_state
{
	llvm_fcall_state_success = 0, // 函数执行成功
	llvm_fcall_state_func_unsupport, // 函数在该目标架构上不支持
	llvm_fcall_state_arch_unsupport, // 该目标架构存在，但未被打包进LLVM发行版中
	llvm_fcall_state_arch_invalid // 该目标架构不存在，是非法值
};

/**
 * LLVM带架构名的函数的信息函数。
 * 其中NVPTX、SPIRV在设计上就未提供AsmParser汇编、Disassembler反汇编组件，XCore未提供AsmParser汇编组件。
 * src中编译单个函数的速度极其缓慢，占用内存达到惊人的16GB，且预处理耗时41.87s。因此不得已拆开#include __pp_for_each__()形式的循环展开头文件，手写每个函数且单独占一个源文件。
 */
#define __llvm_target_func_info_list__()\
	__llvm_target_func_info__(void, LLVMInitialize, TargetInfo, initialize_target_info, __llvm_support_target_list__()),\
	__llvm_target_func_info__(void, LLVMInitialize, Target, initialize_target, __llvm_support_target_list__()),\
	__llvm_target_func_info__(void, LLVMInitialize, TargetMC, initialize_target_mc, __llvm_support_target_list__()),\
	__llvm_target_func_info__(void, LLVMInitialize, Disassembler, initialize_disassembler, __llvm_disassembler_support_target_list__()),\
	__llvm_target_func_info__(void, LLVMInitialize, AsmPrinter, initialize_asm_printer, __llvm_support_target_list__()),\
	__llvm_target_func_info__(void, LLVMInitialize, AsmParser, initialize_asm_parser, __llvm_asm_parser_support_target_list__())

/**
 * @brief 包装函数签名
 */
#define __decl_llvm_target_func_signature__(ret_type, export_name, ...)\
	::sys::llvm::llvm_fcall_state export_name(::sys::llvm::llvm_target target\
			__if_intl__(__not_equal__(ret_type, void))(, ret_type *ret)\
			__va_opt_comma__(__VA_ARGS__) __declaration_list__(__decl_llvm_target_func_decl_list_expand_id__(), __VA_ARGS__))

// 声明函数
#define __decl_llvm_target_func_op__(i, begin_idx, end_idx, const_params, info)\
	__decl_llvm_target_func_op_intl__(__llvm_target_func_info_ret_type__(info), __llvm_target_func_info_export_name__(info), __llvm_target_func_info_args_list__(info))

#define __decl_llvm_target_func_op_intl__(ret_type, export_name, ...)\
	extern __decl_llvm_target_func_signature__(ret_type, export_name, __VA_ARGS__);

#define __decl_llvm_target_func__(...)\
	__for_each__(__decl_llvm_target_func_expand_id__())(__decl_llvm_target_func_op__, , __VA_ARGS__)

__decl_llvm_target_func__(__llvm_target_func_info_list__())

#undef __decl_llvm_target_func__
#undef __decl_llvm_target_func_op_intl__
#undef __decl_llvm_target_func_op__
}
}

#endif//_SYS_LLVM_TARGETFUNC
