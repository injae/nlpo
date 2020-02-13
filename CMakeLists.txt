cmake_minimum_required(VERSION 3.12)

include(cmake/cppm_tool.cmake)
cppm_project()
project(nlpo VERSION 1.0.2 LANGUAGES C CXX)
cppm_setting()

cppm_cxx_standard(17)
cppm_compiler_option(DEFAULT)


find_cppkg(fmt git MODULE fmt::fmt)

cppm_target_define(nlpo STATIC 
SOURCES 
	src/command.cpp
	src/option.cpp
	src/app.cpp)


cppm_target_dependencies(nlpo 
PUBLIC	
	fmt
)

cppm_target_install(nlpo)

