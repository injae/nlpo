cmake_minimum_required(VERSION 3.6)

include(cmake/HunterGate.cmake)
HunterGate(
   URL "https://github.com/ruslo/hunter/archive/v0.23.89.tar.gz"
   SHA1 "a370290a8b32987755a36d64807bf8c7f5b61730"
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



find_cppkg(fmt lastest  MODULE fmt::fmt PRIVATE )

add_library(nlpo STATIC "")
target_sources(nlpo
	PRIVATE 
	src/app.cpp
	src/option.cpp
	src/command.cpp
)
set_target_properties(nlpo PROPERTIES LINKER_LANGUAGE CXX)


cppm_target_install(nlpo STATIC INSTALL)


