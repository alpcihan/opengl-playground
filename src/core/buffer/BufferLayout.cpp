#include "core/buffer/BufferLayout.h"

//////////////////
// Buffer Element
//////////////////
BufferElement::BufferElement(ShaderDataType type, bool isNormalized, const std::string &name)
    : type(type), name(name), byte(shaderDataTypeByte.at(type)), isNormalized(isNormalized) {}

/////////////////
// Buffer Layout
/////////////////
BufferLayout::BufferLayout(std::initializer_list<BufferElement> elements)
    : elements(elements)
{
    this->calculateOffsetsAndStride();
}

void BufferLayout::calculateOffsetsAndStride()
{
    unsigned long offset = 0;

    for (BufferElement &element : this->elements)
    {
        element.offset = offset;
        offset += element.byte;
        this->stride += element.byte;
    }
}

const std::vector<BufferElement> &BufferLayout::getElements() const
{
    return this->elements;
}

unsigned int BufferLayout::getStride() const
{
    return this->stride;
}
