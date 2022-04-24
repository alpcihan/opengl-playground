#include "core/core.h"

float x = 0, y = 0, z = 0;
const float num = 1;

void keyCalls(const GLFWwindow *window)
{
    GLFWwindow *win = (GLFWwindow *)window;

    if (glfwGetKey(win, GLFW_KEY_X) == GLFW_PRESS)
    {
        z += num;
    }

    else if (glfwGetKey(win, GLFW_KEY_Z) == GLFW_PRESS)
    {
        z -= num;
    }

    if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS)
    {
        x += num;
    }

    else if (glfwGetKey(win, GLFW_KEY_A) == GLFW_PRESS)
    {
        x -= num;
    }

    if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS)
    {
        y += num;
    }

    else if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS)
    {
        y -= num;
    }
}

int main()
{
    std::unique_ptr<Window> window = std::make_unique<Window>(WindowProps(1600, 1600));
    OpenGLAPI::init();

    Model backpack("fox-lowp/fox-lowp.obj");

    Shader shader("model-loading.vert", "model-loading.frag");
    shader.bind();

    TransformComponent transform(
        glm::vec3(0.0f),
        glm::vec3(0.0f),
        glm::vec3(0.1f));

    while (!window->isClosed())
    {
        OpenGLAPI::clear();

        /* key calls */
        keyCalls(window->getGLFWwindow());

        /* update the camera */
        glm::vec3 cameraPos = glm::vec3(x, y, 4 + z);
        glm::vec3 cameraUp = glm::vec3(0, 1, 0);
        glm::vec3 cameraFront = glm::vec3(0, 0, -1);

        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        glm::mat4 projection = glm::perspective(glm::radians(45.f), 1.f, 0.1f, 1000.f);

        /* Render comes here. */
        //transform.rotation = glm::vec3(glm::radians((float)glfwGetTime() * 10));
        glm::mat4 model = transform.getTransform();

        glm::mat4 mvp = projection * view * model;
        shader.setMat4("u_mtrx", mvp);

        backpack.draw(shader);

        window->update();
    }

    return 0;
}