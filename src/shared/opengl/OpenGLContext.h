#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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