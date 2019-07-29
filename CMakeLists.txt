cmake_minimum_required(VERSION 3.6)

include(cmake/cppm_tool.cmake)
cppm_project()
project(nlpo VERSION 1.0.1 LANGUAGES C CXX)
cppm_setting()

cppm_cxx_standard(17)
cppm_compiler_option(DEFAULT)


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

