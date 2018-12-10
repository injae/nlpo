cmake_minimum_required(VERSION 3.10)

project(nlpo LANGUAGES CXX VERSION 1.0.0)

message(STATUS "We are on a ${CMAKE_SYSTEM_NAME} system")
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_definitions(-DSYSTEM_LINUX)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    add_definitions(-DSYSTEM_DARWIN)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "AIX")
    add_definitions(-DSYSTEM_AIX)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_definitions(-DSYSTEM_WINDOWS)
endif()
# detect host processor
message(STATUS "The host processor is ${CMAKE_HOST_SYSTEM_PROCESSOR}")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")
set(MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -g -fPIC -O0") 
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")  
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -g -fPIC -O0") 
endif()
find_program(CCACHE_EXE ccache)
if(CCACHE_EXE)
    set(CMAKE_CXX_COMPILER_LAUNCHER ccache)
    message("--- use ccache")
endif()

include(${MODULE_PATH}/cppm_tool.cmake)

set(thirdparty)
download_thirdparty(Boost)
find_package(Boost  COMPONENTS system filesystem REQUIRED)
list(APPEND thirdparty  ${Boost_LIBRARIES})


add_library(nlpo STATIC "")
target_sources(nlpo
	PRIVATE 
	src/app.cpp
	src/option.cpp
	src/command.cpp
)
set_target_properties(nlpo PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(nlpo PUBLIC ${thirdparty})

target_install(nlpo STATIC)


