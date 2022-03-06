#pragma once

#include "shared.h"

class Camera
{
public:
    Camera() = default;
    Camera(const glm::mat4& projection);

    const glm::mat4& getProjection() const { return projection; };

protected:
    glm::mat4 projection = glm::mat4(1.0f);
};