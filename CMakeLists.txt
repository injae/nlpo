cmake_minimum_required(VERSION 3.6)

include(cmake/HunterGate.cmake)
HunterGate(
   URL "https://github.com/ruslo/hunter/archive/v0.23.98.tar.gz"
   SHA1 "bf539cb70375ac319e386ae2ec5b5a0c4923480a"
)
project(nlpo LANGUAGES CXX VERSION 1.0.0)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -g -fPIC -O0") 
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")  
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -g -fPIC -O0") 
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC") 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang") 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
endif()
include(cmake/cppm_tool.cmake)
cppm_setting()
# detect host processor
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

find_cppkg(fmt lastest)

cppm_target_define(nlpo SHARED
SOURCES 
	src/app.cpp
	src/option.cpp
	src/command.cpp)

cppm_target_dependencies(nlpo
PUBLIC
	fmt::fmt
)

cppm_target_install(nlpo)

