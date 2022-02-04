#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class OpenGLContext
{
public:
    static bool init();
    static void clear();
    static void setOpenGLVersionOnce();
};