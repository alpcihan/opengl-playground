#include <iostream>
#include "window/Window.h"
#include "shader/Shader.h"
#include "buffer/VAO.h"
#include <spdlog/spdlog.h>
#include <memory>

int main()
{
    Window window = Window();

    const float vertices[24] = {
        // positions        // colors
         0.5f,  0.5f, 0.0f, 1.0, 0.0, 1.0,
         0.5f, -0.5f, 0.0f, 0.0, 1.0, 1.0,
        -0.5f, -0.5f, 0.0f, 1.0, 1.0, 0.0,
        -0.5f,  0.5f, 0.0f, 1.0, 1.0, 1.0
    };

    unsigned int indices[6] = {  
        0, 1, 3,
        1, 2, 3
    };  

    VAO vao;

    std::shared_ptr<VBO> vbo = std::make_shared<VBO>(vertices, sizeof(float) * 24);
    vbo -> setLayout({
        {ShaderDataType::Vec3, true},
        {ShaderDataType::Vec3, true}
    });

    std::shared_ptr<EBO> ebo = std::make_shared<EBO>(indices, sizeof(unsigned int) * 6);
        
    vao.addVBO(vbo);
    vao.setEBO(ebo);

    Shader shader("resources/shaders/hello-shader.vert", "resources/shaders/hello-shader.frag");
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