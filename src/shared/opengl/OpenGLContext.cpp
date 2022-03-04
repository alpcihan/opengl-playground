#include "opengl/OpenGLContext.h"

OpenGLContext::OpenGLContext(GLFWwindow *window)
    : window(window){}

void OpenGLContext::init()
{
    glfwMakeContextCurrent(this->window);
    this->loadGlad();
}

void OpenGLContext::swapBuffers()
{
    glfwSwapBuffers(this->window);
}

void OpenGLContext::loadGlad()
{ 
    bool success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    if (!success)
        spdlog::error("Could not initialize GLAD!");
}
