cmake_minimum_required(VERSION 3.6)

project(nlpo LANGUAGES CXX VERSION 0.0.1.0)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(MODULE_PATH ${CMAKE_MODULE_PATH}/Modules)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -fPIC -O0 -Qunused-arguments")
include(${CMAKE_MODULE_PATH}/cmake_option.cmake)
include(${CMAKE_MODULE_PATH}/project_maker.cmake)
include(${CMAKE_MODULE_PATH}/utils.cmake)
get_third_party_list()

set(thirdparty 
	nieel::nieel
)
set(source 
	src/option.cpp
	src/main.cpp
	src/args.cpp
	src/option_group.cpp
	src/program.cpp
)
build_binary(nlpo "${source}" "${thirdparty}")



