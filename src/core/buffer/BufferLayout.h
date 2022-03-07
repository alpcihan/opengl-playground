#pragma once

#include "core/shared.h"
#include "core/shader/ShaderType.h"

struct BufferElement
{
public:
    ShaderDataType type;
    std::string name;
    unsigned int byte;
    unsigned long offset;
    bool isNormalized;

public:
    BufferElement() = default;
    BufferElement(ShaderDataType type, bool isNormalized = false, const std::string &name = "");
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
