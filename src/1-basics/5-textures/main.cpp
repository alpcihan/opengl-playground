#include <iostream>
#include "window/Window.h"
#include "shader/Shader.h"
#include "texture/Texture.h"
#include "buffer/VAO.h"
#include <spdlog/spdlog.h>
#include <memory>

int main()
{
    Window window = Window();

    const float vertices[20] = {
        // positions        // tex coords
        0.5f, 0.5f, 0.0f, 2.0, 2.0,
        0.5f, -0.5f, 0.0f, 2.0, 0.0,
        -0.5f, -0.5f, 0.0f, 0.0, 0.0,
        -0.5f, 0.5f, 0.0f, 0.0, 2.0};

    unsigned int indices[6] = {
        0, 1, 3,
        1, 2, 3};

    VAO vao;

    std::shared_ptr<VBO> vbo = std::make_shared<VBO>(vertices, sizeof(float) * 20);
    vbo->setLayout({{ShaderDataType::Vec3, true},
                    {ShaderDataType::Vec2, true}});

    std::shared_ptr<EBO> ebo = std::make_shared<EBO>(indices, sizeof(unsigned int) * 6);

    vao.addVBO(vbo);
    vao.setEBO(ebo);

    Shader shader("resources/shaders/hello-texture.vert", "resources/shaders/hello-texture.frag");
    shader.bind();

    Texture texture0("resources/textures/wall.jpg");
    Texture texture1("resources/textures/pepe.png");

    texture0.bind(0);
    shader.setInt("u_texture0", 0);

    texture1.bind(1);
    shader.setInt("u_texture1", 1);

    while (!window.isClosed())
    {
        window.clear();

        /* Render comes here. */
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        window.update();
    }

    return 0;
}