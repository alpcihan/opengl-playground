cmake_minimum_required(VERSION 3.21)

project(opengl-practices)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")

configure_file(configuration/Directories.h.in configuration/Directories.h)
include_directories(${CMAKE_BINARY_DIR})

add_subdirectory(externals)
add_subdirectory(src)