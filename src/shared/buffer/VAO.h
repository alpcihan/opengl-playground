#pragma once

#include <vector>
#include "VBO.h"
#include "EBO.h"

class VAO
{
public:
    VAO();
    ~VAO();

    void bind() const;
    void unbind() const;

    void addVBO(const std::shared_ptr<VBO> &vbo);
    void setEBO(const std::shared_ptr<EBO> &ebo);

    const std::vector<std::shared_ptr<VBO>>& getVBOs() const { return vbos; }
	const std::shared_ptr<EBO>& getEBO() const { return ebo; }

private:
    unsigned int id;
    unsigned int attribPointerCount = 0;
    std::vector<std::shared_ptr<VBO>> vbos;
    std::shared_ptr<EBO> ebo;

private:
    void setAttribPointers(const BufferLayout &layout);
    void setFloatAttrib(const BufferElement &bufferElement, const unsigned int stride);
    void setIntAttrib(const BufferElement &bufferElement, const unsigned int stride);
};
