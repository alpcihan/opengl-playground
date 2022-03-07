#pragma once

#include "core/shared.h"
#include "core/buffer/BufferLayout.h"

class VBO
{
public:
    VBO(unsigned int size);
    VBO(const float *vertices, unsigned int size);
    VBO(const float *vertices, unsigned int size, const BufferLayout &layout);
    ~VBO();

    void setLayout(const BufferLayout &layout);
    const BufferLayout &getLayout() const;

    void setData(const float *vertices, unsigned int size);

    void bind() const;
    void unbind() const;

private:
    unsigned int id;
    BufferLayout layout;
};