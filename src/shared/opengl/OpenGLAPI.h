#pragma once

#include "shared.h"
#include "buffer/VAO.h"

namespace OpenGLAPI
{   
    void init();
	void draw(const std::shared_ptr<VAO>& vao);
	void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
	void setClearColor(const glm::vec4& color);
	void clear();
}