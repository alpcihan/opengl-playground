#include "buffer/BufferLayout.h"
#include "shader/ShaderType.h"

//////////////////
// Buffer Element
//////////////////
BufferElement::BufferElement(ShaderDataType type, const std::string &name, bool isNormalized)
    : type(type), name(name), size(), isNormalized(isNormalized) {}

/////////////////
// Buffer Layout
/////////////////
BufferLayout::BufferLayout(std::initializer_list<BufferElement> elements)
    : elements(elements) {}

void BufferLayout::calculateOffsetsAndStride()
{
    unsigned long offset = 0;

    for (BufferElement &element : elements)
    {
        element.offset = offset;
        offset += element.size;
        this->stride += element.size;
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
