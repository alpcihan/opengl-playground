set(CHAPTERS
    1-basics
)

set(
    1-basics
    1-hello-window
)

foreach(CHAPTER ${CHAPTERS})
    foreach(PROJECT ${${CHAPTER}})
        file(GLOB SOURCE
            "${CHAPTER}/${PROJECT}/*.h"
            "${CHAPTER}/${PROJECT}/*.hpp"
            "${CHAPTER}/${PROJECT}/*.cpp"
            "${CHAPTER}/${PROJECT}/*.c"
        )
        set(NAME "${CHAPTER}_${PROJECT}")
        add_executable(${NAME} ${SOURCE})
        target_link_libraries(${NAME} externals)
    endforeach(PROJECT)
endforeach(CHAPTER)