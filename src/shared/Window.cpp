#include "Window.h"
#include "spdlog/spdlog.h"

static unsigned windowCount = 0;

Window::Window(const WindowProps &windowProps)
    : windowProps(windowProps)
{
    this->initialize();
}

Window::~Window()
{
    this->shutdown();
}

void Window::update() const
{
    glfwMakeContextCurrent(this->window);
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void Window::clear() const
{
    glfwMakeContextCurrent(this->window);
    OpenGLContext::clear();
}

bool Window::isClosed() const
{
    return glfwWindowShouldClose(this->window);
}

void Window::initialize()
{
    if (windowCount == 0)
    {
        bool success = glfwInit();
        if (!success)
            spdlog::error("Could not initialize GLFW!");
        else
            OpenGLContext::setOpenGLVersionOnce();
    }

    this->window = glfwCreateWindow(
        this->windowProps.width,
        this->windowProps.height,
        this->windowProps.title.c_str(),
        NULL,
        NULL);

    if (!this->window)
        spdlog::error("Could not initialize window!");
    else
        ++windowCount;

    glfwMakeContextCurrent(this->window);

    OpenGLContext::init();
}

void Window::shutdown() const
{
    glfwDestroyWindow(this->window);
    --windowCount;

    if (windowCount == 0)
        glfwTerminate();
}