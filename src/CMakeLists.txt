set(CONTENTS
    practices
)

set(practices
    1-hello-window
    2-hello-triangle
    3-shader
    4-hello-rectangle
    5-textures
    6-transformations
    7-camera
)

foreach(CONTENT ${CONTENTS})
    foreach(PROJECT ${${CONTENT}})
        file(GLOB_RECURSE SOURCE
            "${CONTENT}/${PROJECT}/*.cpp"
            "${CONTENT}/${PROJECT}/*.c"
            "core/*.c"
            "core/*.cpp"
        )
        set(NAME "${CONTENT}_${PROJECT}")

        add_executable(${NAME} ${SOURCE})
        target_include_directories(${NAME} 
            PUBLIC "./"
        )
        target_link_libraries(${NAME} externals)
    endforeach(PROJECT)
endforeach(CONTENT)