#include "buffer/VBO.h"
#include <glad/glad.h>

VBO::VBO(unsigned int size)
{
    glGenBuffers(1, &this->id);
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
    glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

VBO::VBO(const float *vertices, unsigned int size)
{
    glGenBuffers(1, &this->id);
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

VBO::VBO(const float *vertices, unsigned int size, const BufferLayout &layout)
{
    glGenBuffers(1, &this->id);
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    this -> setLayout(layout);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &this->id);
}

void VBO::setLayout(const BufferLayout &layout)
{
    this->layout = layout;
}

const BufferLayout &VBO::getLayout() const
{
    return this->layout;
}

void VBO::setData(const float *data, unsigned int size)
{
    this->bind();
    glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
}

void VBO::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
}

void VBO::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
