cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(sys-llvm)

set(PROJECT_PACKAGE_NAME sys_llvm)

# Set zlib find path. zlib doesn't have Config.cmake so find_package() cannot find it.
set(CMAKE_PREFIX_PATH "C:/msys64/ucrt64")
find_package(LLVM REQUIRED)
find_package(ppmp REQUIRED)
find_package(arch REQUIRED)

# link_directories() must be called before target is created.
link_directories("${arch_LIBRARY_DIRS}")

set(PROJECT_SOURCE_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

add_compile_options(-g -Og -ftime-report -ftime-report-details)

# Build as static library
add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_INCLUDE_DIRS}")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOURCE_DIR}")
target_include_directories(${PROJECT_NAME} PUBLIC "${ppmp_INCLUDE_DIRS}")
target_include_directories(${PROJECT_NAME} PUBLIC "${arch_INCLUDE_DIRS}")

target_compile_definitions(${PROJECT_NAME} PUBLIC ${LLVM_DEFINITIONS})

# Set LLVM enabled target arch
# DO NOTE that not all targets are provided in msys2 package
# Target arch name is case sensitive
# Backend target should be involved in ${LLVM_TARGETS_TO_BUILD}
set(LLVM_ENABLED_TARGETS_LIST X86)

set(LLVM_EXT_COMPONENTS_LIST Object)

# Generate inc files
include("./cmake/code_gen.cmake")

llvm_map_components_to_libnames(LLVM_FULL_LINK_LIBRARIES ${LLVM_EXT_COMPONENTS_LIST} ${LLVM_ENABLED_TARGETS_LIST})
set(LLVM_LINK_LIBRARIES)

# Remove components related to IR
set(LLVM_DISABLE_COMPONENTS_LIST CodeGen)

# Components to be removed in supermassive arch module
foreach(lib ${LLVM_FULL_LINK_LIBRARIES})
	set(keep TRUE)
	foreach(disable ${LLVM_DISABLE_COMPONENTS_LIST})
		if(lib MATCHES ${disable})
			set(keep FALSE)
			break()
		endif()
	endforeach()
	if(keep)
		list(APPEND LLVM_LINK_LIBRARIES ${lib})
	endif()
endforeach()

# ${LLVM_LINK_LIBRARIES} will be automatically‌ passed to downstream projects
set(PROJECT_EXTLINK_LIBRARIES ${LLVM_LINK_LIBRARIES} "${arch_LIBRARIES}")
target_link_libraries(${PROJECT_NAME} ${PROJECT_EXTLINK_LIBRARIES})

# Install
set(PROJECT_INSTALL_LIBRARIES ${PROJECT_NAME})
include("./cmake/install.cmake")