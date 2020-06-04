cmake_minimum_required(VERSION 3.12)

set(CPPM_VERSION 0.0.13)
include(cmake/cppm_loader.cmake)
cppm_project()

project(nlpo VERSION 0.0.3 LANGUAGES C CXX)
cppm_setting()
cppm_cxx_standard(17)
cppm_compiler_option(DEFAULT)

find_cppkg(fmt 8.0.1  MODULE fmt::fmt-header-only TYPE lib)


cppm_target_define(nlpo STATIC NAMESPACE nlpo
SOURCES
    src/command.cpp
    src/option.cpp
    src/app.cpp
)


set(nlpo_global_deps PRIVATE fmt)
cppm_target_dependencies(nlpo
   ${nlpo_global_deps})


cppm_target_install(nlpo)

