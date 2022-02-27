#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

struct TransformComponent
{
public:
    glm::vec3 translation = {0.0f, 0.0f, 0.0f};
    glm::vec3 rotation = {0.0f, 0.0f, 0.0f};
    glm::vec3 scale = {1.0f, 1.0f, 1.0f};

public:
    TransformComponent() = default;
    TransformComponent(const glm::vec3 &translation,
                       const glm::vec3 &rotation,
                       const glm::vec3 &scale)
        : translation(translation), rotation(rotation), scale(scale){};

    glm::mat4 getTransform() const
    {
        return glm::translate(glm::mat4(1.0f), translation) *
               glm::toMat4(glm::quat(rotation)) *
               glm::scale(glm::mat4(1.0f), scale);
    }
};