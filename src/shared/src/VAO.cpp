#include "buffer/VAO.h"
#include <glad/glad.h>

VAO::VAO()
{
    glGenVertexArrays(1, &this->id);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &this->id);
}

void VAO::bind() const
{
    glBindVertexArray(this->id);
}

void VAO::unbind() const
{
    glBindVertexArray(0);
}

void VAO::addVBO(const std::shared_ptr<VBO> &vbo)
{
    this->bind();
    vbo->bind();

    const BufferLayout &layout = vbo->getLayout();
    setAttribPointers(layout);
}

void VAO::setEBO(const std::shared_ptr<EBO> &ebo)
{
    this->bind();
    ebo->bind();

    this->ebo = ebo;
}

void VAO::setAttribPointers(const BufferLayout &layout)
{
    const std::vector<BufferElement>& bufferElements = layout.getElements();

    for (const BufferElement &bufferElement : bufferElements)
    {
        switch (bufferElement.type)
        {
        case ShaderDataType::Int:
        case ShaderDataType::IVec2:
        case ShaderDataType::IVec3:
        case ShaderDataType::IVec4:
        case ShaderDataType::Bool:
        {
            setIntAttrib(bufferElement, layout.getStride());
            break;
        }
        case ShaderDataType::Float:
        case ShaderDataType::Vec2:
        case ShaderDataType::Vec3:
        case ShaderDataType::Vec4:
        {
            setFloatAttrib(bufferElement, layout.getStride());
            break;
        }
        }
    }
}

void VAO::setFloatAttrib(const BufferElement &bufferElement, const unsigned int stride)
{
    glEnableVertexAttribArray(this -> attribPointerCount);

    glVertexAttribPointer(attribPointerCount,
                          bufferElement.size,
                          shaderDataTypeToGLTypeMap.find(bufferElement.type)->second,
                          bufferElement.isNormalized ? GL_TRUE : GL_FALSE,
                          stride,
                          (const void *)bufferElement.offset);

    (this -> attribPointerCount)++;
}

void VAO::setIntAttrib(const BufferElement &bufferElement, const unsigned int stride)
{
    glEnableVertexAttribArray(this -> attribPointerCount);

    glVertexAttribIPointer(attribPointerCount,
                          bufferElement.size,
                          shaderDataTypeToGLTypeMap.find(bufferElement.type)->second,
                          stride,
                          (const void *)bufferElement.offset);

    (this -> attribPointerCount)++;
}