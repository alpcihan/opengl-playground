#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class OpenGLContext
{
public:
    static bool loadGlad();
    static void clear();
    static void setOpenGLVersionOnce();
};