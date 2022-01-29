#include "OpenGLContext.h"
#include "spdlog/spdlog.h"

bool OpenGLContext::init()
{
    bool success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    if (!success)
        spdlog::error("Could not initialize GLAD!");

    return success;
}

void OpenGLContext::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLContext::setOpenGLVersionOnce()
{
    static bool isVersionSet = false;

    if(isVersionSet) {
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    isVersionSet = true;
}
