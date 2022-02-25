add_library(externals)

add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(spdlog)

target_include_directories(
    externals 
    PUBLIC glad/include
    PUBLIC stb_image/include
)

target_sources(
    externals
    PUBLIC glad/src/glad.c
    PUBLIC stb_image/src/stb_image.cpp
)

target_link_libraries(
    externals 
    glfw
    glm
    spdlog
)