#include "window/Window.h"
#include "opengl/OpenGLAPI.h"

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
    this->openGLContext->swapBuffers();
    glfwPollEvents();
}

void Window::clear() const
{
    OpenGLAPI::clear();
}

bool Window::isClosed() const
{
    return glfwWindowShouldClose(this->window);
}

void Window::initialize()
{
    static bool isFirstWindow = true;

    if (isFirstWindow)
    {
        this->initializeGLFW();
        isFirstWindow = false;
    }

    this->createWindow();
    openGLContext = std::make_unique<OpenGLContext>(window);
    openGLContext->init();
}

void Window::initializeGLFW() const
{
    bool success = glfwInit();
    if (!success){
        spdlog::error("Could not initialize GLFW!");
        return;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void Window::createWindow()
{
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
}

void Window::shutdown() const
{
    glfwDestroyWindow(this->window);
    --windowCount;

    if (windowCount == 0)
        glfwTerminate();
}