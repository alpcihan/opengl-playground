#pragma once

#include "core/shared.h"

class OpenGLContext
{
public:
    OpenGLContext(GLFWwindow* window);
    
    void init();
    void swapBuffers();

private:
    GLFWwindow* window;

private:
    void loadGlad();
};