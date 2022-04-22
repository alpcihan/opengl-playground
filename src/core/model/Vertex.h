#pragma once

#include "core/shared.h"

struct Vertex
{
public:
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;

public:
    Vertex() = default;

    Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 texCoords)
        : position(position), normal(normal), texCoords(texCoords)
    {}

    Vertex(float x, float y, float z, float nx, float ny, float nz, float u, float v)
        : position(glm::vec3(x, y, z)), normal(glm::vec3(nx, ny, nz)) ,texCoords(glm::vec2(u, v))
    {}
};