set(CHAPTERS
    1-basics
)

set(1-basics
    1-hello-window
    2-hello-triangle
    3-shader
    4-hello-rectangle
    5-textures
)

foreach(CHAPTER ${CHAPTERS})
    foreach(PROJECT ${${CHAPTER}})
        file(GLOB_RECURSE SOURCE
            "${CHAPTER}/${PROJECT}/*.h"
            "${CHAPTER}/${PROJECT}/*.hpp"
            "${CHAPTER}/${PROJECT}/*.cpp"
            "${CHAPTER}/${PROJECT}/*.c"
            "shared/*.c"
            "shared/*.cpp"
        )
        set(NAME "${CHAPTER}_${PROJECT}")

        add_executable(${NAME} ${SOURCE})
        target_include_directories(${NAME} 
            PUBLIC "${CHAPTER}/${PROJECT}"
            PUBLIC "shared"
        )
        target_link_libraries(${NAME} externals)
    endforeach(PROJECT)
endforeach(CHAPTER)