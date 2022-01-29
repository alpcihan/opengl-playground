#pragma once

#include <iostream>
#include "OpenGLContext.h"

struct WindowProps
{
    unsigned width;
    unsigned height;
    std::string title;

    WindowProps(unsigned width = 1600,
                unsigned height = 900,
                const std::string &title = "My Project")
        : title(title), width(width), height(height)
    {
    }
};

class Window
{
public:
    WindowProps windowProps;

public:
    Window(const WindowProps &windowProps = WindowProps());
    ~Window();

    void update();
    void clear();

    bool isClosed();

private:
    GLFWwindow *window;
    
private:
    void initialize();
    void shutdown();
};
