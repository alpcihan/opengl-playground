#pragma once

#include "BufferLayout.h"

class VBO
{
public:
    VBO(unsigned int size);
    VBO(float *vertices, unsigned int size);
    ~VBO();

    void setLayout(const BufferLayout &layout);
    const BufferLayout &getLayout() const;

    void setData(const void *vertices, unsigned int size);

    void bind() const;
    void unbind() const;

private:
    unsigned int id;
    BufferLayout layout;
};