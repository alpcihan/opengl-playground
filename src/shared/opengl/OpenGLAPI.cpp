#include "opengl/OpenGLAPI.h"

namespace OpenGLAPI
{
    void init()
    {
        glEnable(GL_DEPTH_TEST);
    }

    void draw(const std::shared_ptr<VAO>& vao)
    {
        unsigned int indexCount = vao->getEBO()->getIndexCount();
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    }

    void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        glViewport(x, y, width, height);
    }

    void setClearColor(const glm::vec4 &color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

}