#include "VAO.h"

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

    const std::vector<BufferElement> &bufferElements = vbo->getLayout().getElements();
    setAttribPointers(bufferElements);
}

void VAO::setEBO(const std::shared_ptr<EBO> &ebo)
{
    this->bind();
    ebo->bind();

    this->ebo = ebo;
}

void VAO::setAttribPointers(const std::vector<BufferElement> &bufferElements)
{
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
            setIntAttrib(bufferElement);
            break;
        }
        case ShaderDataType::Float:
        case ShaderDataType::Vec2:
        case ShaderDataType::Vec3:
        case ShaderDataType::Vec4:
        {
            setFloatAttrib(bufferElement);
            break;
        }
        }
    }
}

void VAO::setFloatAttrib(const BufferElement &bufferElement)
{
    const unsigned index = this->attribPointerCount;
    unsigned short count = bufferElement.size

    glEnableVertexAttribArray(attribPointerCount);

    glVertexAttribPointer(attribPointerCount,
                          bufferElement.GetComponentCount(),
                          ShaderDataTypeToOpenGLBaseType(element.Type),
                          element.Normalized ? GL_TRUE : GL_FALSE,
                          layout.GetStride(),
                          (const void *)element.Offset);
    m_VertexBufferIndex++;
}
void VAO::setIntAttrib(const BufferElement &bufferElement)
{
}