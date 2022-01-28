cmake_minimum_required(VERSION 3.21)

project(opengl-practices)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")

add_subdirectory(externals)
add_subdirectory(src)