add_library(externals)

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
)