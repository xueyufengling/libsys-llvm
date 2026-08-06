# Check LLVM
if(NOT DEFINED LLVM_ALL_TARGETS)
	message(WARNING "LLVM_ALL_TARGETS is not defined. this file should be included after find_package(LLVM)")
endif()

# Retrived all targets
set(LLVM_ALL_SUPPORT_TARGETS ${LLVM_ALL_TARGETS} ${LLVM_ALL_EXPERIMENTAL_TARGETS})
list(REMOVE_DUPLICATES LLVM_ALL_SUPPORT_TARGETS)

list(JOIN LLVM_ALL_SUPPORT_TARGETS ", " LLVM_ALL_SUPPORT_TARGETS_MACRO)

set(TARGET_LIST_HEADER_FILE "${CMAKE_CURRENT_SOURCE_DIR}/include/sys/llvm/target_list.h")
# Generate support target list
file(WRITE ${TARGET_LIST_HEADER_FILE}
	"#ifndef __SYS_LLVM_TARGETLIST\n"
	"#define __SYS_LLVM_TARGETLIST\n\n"
	"#include <ppmp/equal.h>\n\n"
	"#define __llvm_support_target_list__() ${LLVM_ALL_SUPPORT_TARGETS_MACRO}\n\n"
)
# LLVM build arch detect
# find existed target and define macro
foreach(target ${LLVM_TARGETS_TO_BUILD})
	message(STATUS "find build target: ${target}")
	file(APPEND ${TARGET_LIST_HEADER_FILE}
	"#define __llvm_build_target_${target}__() 1\n"
	"#define __equal_def__${target}(x) x\n\n"
	)
endforeach()
file(APPEND ${TARGET_LIST_HEADER_FILE}
	"#endif// __SYS_LLVM_TARGETLIST\n"
)
message(STATUS "Generated ${CMAKE_CURRENT_SOURCE_DIR}/include/sys/llvm/target_list.h")

set(TARGET_DISPATCH_ALL_INC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/src/target_func/incl/defs/def_llvm_target_func_dispatch_all.cpp.inc")
# Generated dispatch function defs
file(WRITE ${TARGET_DISPATCH_ALL_INC_FILE} "")
foreach(target ${LLVM_ALL_SUPPORT_TARGETS}) 
	file(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/src/target_func/incl/defs/def_llvm_target_func_${target}.cpp.inc"
		"#define __llvm_target_arch__() ${target}\n"
		"#if defined(__llvm_build_target_${target}__)\n"
		"#include \"target_func/incl/def_llvm_target_func_support.cpp.inc\"\n"
		"#else\n"
		"#include \"target_func/incl/def_llvm_target_func_unsupport.cpp.inc\"\n"
		"#endif"
	)
	file(APPEND ${TARGET_DISPATCH_ALL_INC_FILE}
		"#include \"def_llvm_target_func_${target}.cpp.inc\"\n"
	)
	message(STATUS "Generated dispatch function def for target ${target}")
endforeach()
