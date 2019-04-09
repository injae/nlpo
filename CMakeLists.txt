cmake_minimum_required(VERSION 3.6)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
project(nlpo LANGUAGES CXX VERSION 1.0.0)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread -fPIC -O0 -g -std=c++17") 
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")  
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread -fPIC -O0 -g -std=c++17") 
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC") 
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} /std:c++17 /MP")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang") 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
endif()
include(cppm_tool)
cppm_load()
set(CMAKE_CXX_STANDARD 17)


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

