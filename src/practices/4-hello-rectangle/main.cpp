#include "core/core.h"

int main()
{
    Window window = Window();

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    const float vertices[24] = {
        // positions        // colors
         0.5f,  0.5f, 0.0f, 1.0, 0.0, 1.0,
         0.5f, -0.5f, 0.0f, 0.0, 1.0, 1.0,
        -0.5f, -0.5f, 0.0f, 1.0, 1.0, 0.0,
        -0.5f,  0.5f, 0.0f, 1.0, 1.0, 1.0
    };

    unsigned int indices[] = {  
        0, 1, 3,
        1, 2, 3
    };  

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float) * 3));

    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

    Shader shader("hello-shader.vert", "hello-shader.frag");
    shader.bind();

    while (!window.isClosed())
    {
        window.clear();

        /* Render comes here. */
        shader.setFloat("uTime", glfwGetTime());

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        window.update();
    }

    return 0;
}