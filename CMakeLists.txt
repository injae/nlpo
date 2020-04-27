cmake_minimum_required(VERSION 3.12)

if(NOT IS_CPPM_LOADED)
    include(cmake/cppm_tool.cmake)
endif()
cppm_project()

project(nlpo VERSION 1.0.3 LANGUAGES C CXX)
cppm_setting()
cppm_cxx_standard(17)
cppm_compiler_option(DEFAULT)

find_cppkg(fmt 6.0.0 MODULE fmt::fmt)


cppm_target_define(nlpo SHARED NAMESPACE nlpo
SOURCES
    src/command.cpp
    src/option.cpp
    src/app.cpp
)


set(global_deps PUBLIC fmt)
cppm_target_dependencies(nlpo
   ${global_deps})


cppm_target_install(nlpo)

