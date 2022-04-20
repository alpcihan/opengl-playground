#pragma once

#include "core/shared.h"

struct Vertex
{
    Vertex(float x, float y, float z, float u, float v)
        : position(glm::vec3(x,y,z)), texCoords(glm::vec2(u,v))
    {}

    glm::vec3 position;
    glm::vec2 texCoords;
};