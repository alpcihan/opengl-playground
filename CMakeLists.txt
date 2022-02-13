cmake_minimum_required(VERSION 3.21)

project(opengl-practices)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")

configure_file(configuration/RootDir.h.in configuration/RootDir.h)
include_directories(${CMAKE_BINARY_DIR}/configuration)

add_subdirectory(externals)
add_subdirectory(src)