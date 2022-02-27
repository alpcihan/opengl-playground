#include "window/Window.h"
#include "shader/Shader.h"
#include "texture/Texture.h"
#include "buffer/VAO.h"
#include "components/TransformComponent.h"

#include <spdlog/spdlog.h>
#include <memory>

int main()
{
    Window window = Window(WindowProps(1600, 1600));
    glEnable(GL_DEPTH_TEST);

    const float vertices[] = {
        // front            
        0.5, 0.5, 0.5,      1.0, 1.0,
        0.5, -0.5, 0.5,     1.0, 0.0,
        -0.5, -0.5, 0.5,    0.0, 0.0,
        -0.5, 0.5, 0.5,     0.0, 1.0,
        // back
        0.5, 0.5, -0.5,     1.0, 1.0,
        0.5, -0.5, -0.5,    1.0, 0.0,
        -0.5, -0.5, -0.5,   0.0, 0.0,
        -0.5, 0.5, -0.5,    0.0, 1.0,
        // right
        0.5, 0.5, -0.5,     1.0, 1.0,
        0.5, -0.5, -0.5,    1.0, 0.0,
        0.5, -0.5, 0.5,     0.0, 0.0,
        0.5, 0.5, 0.5,      0.0, 1.0,
        // left
        -0.5, 0.5, 0.5,     1.0, 1.0,
        -0.5, -0.5, 0.5,    1.0, 0.0,
        -0.5, -0.5, -0.5,   0.0, 0.0,
        -0.5, 0.5, -0.5,    0.0, 1.0,
        // top
        0.5, 0.5, -0.5,     1.0, 1.0,
        0.5, 0.5, 0.5,      1.0, 0.0,
        -0.5, 0.5, 0.5,     0.0, 0.0,
        -0.5, 0.5, -0.5,    0.0, 1.0,
        // bottom
        0.5, -0.5, -0.5,    1.0, 1.0,
        0.5, -0.5, 0.5,     1.0, 0.0,
        -0.5, -0.5, 0.5,    0.0, 0.0,
        -0.5, -0.5, -0.5,   0.0, 1.0};

    unsigned int indices[] = {
        // front
        0, 1, 2,
        2, 3, 0,
        // back
        4, 5, 6,
        6, 7, 4,
        // right
        8, 9, 10,
        10, 11, 8,
        // left
        12, 13, 14,
        14, 15, 12,
        // top
        16, 17, 18,
        18, 19, 16,
        // bottom
        20, 21, 22,
        22, 23, 20,
    };

    VAO vao;

    std::shared_ptr<VBO> vbo = std::make_shared<VBO>(vertices, sizeof(float) * 120);
    vbo->setLayout({{ShaderDataType::Vec3, true},
                    {ShaderDataType::Vec2, true}});

    std::shared_ptr<EBO> ebo = std::make_shared<EBO>(indices, sizeof(unsigned int) * 36);

    vao.addVBO(vbo);
    vao.setEBO(ebo);

    Shader shader("resources/shaders/hello-transformations.vert", "resources/shaders/hello-texture.frag");
    shader.bind();

    Texture texture0("resources/textures/wall.jpg");
    Texture texture1("resources/textures/pepe.png");

    texture0.bind(0);
    shader.setInt("u_texture0", 0);

    texture1.bind(1);
    shader.setInt("u_texture1", 1);

    TransformComponent transform(
        glm::vec3(-0.2f, -0.2f, 0.0f),
        glm::vec3(0.0f),
        glm::vec3(0.5, 0.5, 0.5));

    while (!window.isClosed())
    {
        window.clear();

        /* Render comes here. */
        transform.rotation = glm::vec3(glm::radians((float)glfwGetTime() * 10));
        glm::mat4 mtrx = transform.getTransform();

        shader.setMat4("u_transform", mtrx);

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        window.update();
    }

    return 0;
}