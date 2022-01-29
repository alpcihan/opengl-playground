add_library(externals)

add_subdirectory(glfw)
add_subdirectory(glm)

target_include_directories(
    externals 
    PUBLIC glad/include
)

target_sources(
    externals
    PUBLIC glad/src/glad.c
)

target_link_libraries(
    externals 
    glfw
    glm
    spdlog
)