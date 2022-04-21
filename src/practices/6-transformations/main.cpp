#include "core/core.h"

int main()
{
    Window window = Window(WindowProps(1600, 1600));

    const float vertices[20] = {
        // positions        // tex coords
        0.5f, 0.5f, 0.0f, 1.0, 1.0,
        0.5f, -0.5f, 0.0f, 1.0, 0.0,
        -0.5f, -0.5f, 0.0f, 0.0, 0.0,
        -0.5f, 0.5f, 0.0f, 0.0, 1.0};

    unsigned int indices[6] = {
        0, 1, 3,
        1, 2, 3};

    VAO vao;

    std::shared_ptr<VBO> vbo = std::make_shared<VBO>(vertices, sizeof(float) * 20);
    vbo->setLayout({{ShaderDataType::Vec3, true},
                    {ShaderDataType::Vec2, true}});

    std::shared_ptr<EBO> ebo = std::make_shared<EBO>(indices, 6);

    vao.addVBO(vbo);
    vao.setEBO(ebo);

    Shader shader("hello-transformations.vert", "hello-texture.frag");
    shader.bind();

    Texture texture0("wall.jpg");
    Texture texture1("pepe.png");

    texture0.bind(0);
    shader.setInt("u_texture0", 0);

    texture1.bind(1);
    shader.setInt("u_texture1", 1);

    while (!window.isClosed())
    {
        window.clear();

        /* Render comes here. */
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(-0.2f, -0.2f, 0.0f));
        trans = glm::rotate(trans, glm::radians((float)glfwGetTime() * 10), glm::vec3(0.0, 0.0, 1.0));
        trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

        shader.setMat4("u_transform", trans);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        window.update();
    }

    return 0;
}