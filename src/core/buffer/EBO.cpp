#include "core/buffer/EBO.h"

EBO::EBO(unsigned int *indices, unsigned int indexCount)
    : indexCount(indexCount)
{
    glGenBuffers(1, &this->id);
    this->bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

EBO::~EBO()
{
    glDeleteBuffers(1, &this->id);
}

void EBO::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
}

void EBO::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int EBO::getIndexCount() const
{
    return this->indexCount;
}
