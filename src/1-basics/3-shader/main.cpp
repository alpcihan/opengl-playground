#include <iostream>
#include "Window.h"
#include "spdlog/spdlog.h"

void linkProgram(const unsigned int program, const unsigned int vertexShader, const unsigned int fragmentShader)
{
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    int isProgramLinked;
    glGetShaderiv(program, GL_LINK_STATUS, &isProgramLinked);

    if (!isProgramLinked)
    {
        int length;
        char logMessage[1024];
        glGetProgramInfoLog(program, 1024, NULL, logMessage);
        const std::string str = "Failed to link the program: " + std::string(logMessage);
        spdlog::error(str);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

unsigned int createShader(const int &shaderType, const char *shaderSource)
{
    const unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    int isShaderCompiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &isShaderCompiled);

    if (!isShaderCompiled)
    {
        char logMessage[1024];
        glGetShaderInfoLog(shader, 1024, NULL, logMessage);
        const std::string str = "Failed to compile fragment shader: " + std::string(logMessage);
        spdlog::error(str);
    }

    return shader;
} 

unsigned int initProgram()
{
    const char *vertexShaderSource = R"VERTEX(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec3 aColor;
        uniform float uTime;

        out vec3 vertexColor;

        void main()
        {
            float offset = 0.5*sin(uTime);
            gl_Position = vec4(offset+aPos, 1.0);
            vertexColor = aColor;
        }
    )VERTEX";

    const char *fragmentShaderSource = R"FRAGMENT(
        #version 330 core
        in vec3 vertexColor;
        uniform float uTime;

        out vec4 FragColor;

        void main()
        {
            float brightness = abs(sin(uTime));
            FragColor = vec4(brightness*vertexColor, 1.0f);
        }
    )FRAGMENT";

    const unsigned int program = glCreateProgram();
    const unsigned int vertexShader = createShader(GL_VERTEX_SHADER, vertexShaderSource);
    const unsigned int fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    linkProgram(program, vertexShader, fragmentShader);

    glUseProgram(program);

    return program;
}

int main()
{
    Window window = Window();

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    const float positions[18] = {
        // positions         // colors
        -0.5f, -0.5f, 0.0f,  1.0, 0.0, 1.0,
         0.5f, -0.5f, 0.0f,  0.0, 1.0, 1.0,
         0.0f,  0.5f, 0.0f,  1.0, 1.0, 0.0
    };

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float) * 3));

    const unsigned int program = initProgram();
    int uTime = glGetUniformLocation(program, "uTime");

    while (!window.isClosed())
    {
        window.clear();

        /* Render comes here. */
        glUniform1f(uTime, glfwGetTime());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.update();
    }

    return 0;
}