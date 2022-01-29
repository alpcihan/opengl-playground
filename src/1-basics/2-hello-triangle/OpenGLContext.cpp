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
