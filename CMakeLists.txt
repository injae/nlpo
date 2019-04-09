cmake_minimum_required(VERSION 3.6)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
project(nlpo LANGUAGES C CXX VERSION 1.0.0)

include(cppm_tool)
cppm_load()
cppm_compiler_option(
	DEBUG
		CLANG "-std=c++17"
		GCC   "-std=c++17"
	RELEASE
		CLANG "-std=c++17"
		GCC   "-std=c++17"
)


find_cppkg(fmt lastest  )

cppm_target_define(nlpo STATIC 
SOURCES 
	src/app.cpp
	src/option.cpp
	src/command.cpp)


cppm_target_dependencies(nlpo 
PUBLIC	
	fmt::fmt
)

cppm_target_install(nlpo)

