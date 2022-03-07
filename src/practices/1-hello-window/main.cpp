#include "core/core.h"
#include <iostream>

int main() 
{
    const bool isGlfwInitialized = glfwInit();

    if (!isGlfwInitialized) 
    {
        std::cout << "Failed to initialize GLFW!" << std::endl;
        return 0;
    }

    GLFWwindow *window = glfwCreateWindow(800, 600, "hello-window", NULL, NULL);

    if (!window) 
    {
        glfwTerminate();
        return 0;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
        std::cout << "Failed to initialize GLAD!" << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window)) 
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}