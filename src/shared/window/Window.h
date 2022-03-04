#pragma once

#include "shared.h"
#include "opengl/OpenGLContext.h"

struct WindowProps
{
    unsigned width;
    unsigned height;
    std::string title;

    WindowProps(unsigned width = 1600,
                unsigned height = 900,
                const std::string &title = "My Project")
        : title(title), width(width), height(height) {}
};

class Window
{
public:
    Window(const WindowProps &windowProps = WindowProps());
    ~Window();

    void update() const;
    void clear() const;

    bool isClosed() const;

private:
    GLFWwindow *window;
    WindowProps windowProps;
    std::unique_ptr<OpenGLContext> openGLContext;
    
private:
    void initialize();
    void initializeGLFW() const;
    void createWindow();

    void shutdown() const;
};
