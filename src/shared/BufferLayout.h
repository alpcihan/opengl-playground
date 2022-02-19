#pragma once

#include <string>
#include <vector>
#include <initializer_list>
#include "ShaderType.h"

struct BufferElement
{
public:
    ShaderDataType type;
    std::string name;
    unsigned int size;
    unsigned long offset;
    bool isNormalized;

public:
    BufferElement() = default;
    BufferElement(ShaderDataType type, const std::string &name, bool isNormalized = false);
};

struct BufferLayout
{
public:
    BufferLayout() = default;
    BufferLayout(std::initializer_list<BufferElement> elements);

    const std::vector<BufferElement> &getElements() const;
    unsigned int getStride() const;

private:
    std::vector<BufferElement> elements;
    unsigned int stride = 0;

private:
    void calculateOffsetsAndStride();
};
