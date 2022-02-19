#pragma once

#include <glad/glad.h>
#include <unordered_map>
#include <string>

enum ShaderType
{
    Fragment = GL_FRAGMENT_SHADER,
    Vertex = GL_VERTEX_SHADER,
    Geometry = GL_GEOMETRY_SHADER
};

enum class ShaderDataType
{
    Int,
    IVec2,
    IVec3,
    IVec4,
    Float,
    Vec2,
    Vec3,
    Vec4,
    Bool
};

extern const std::unordered_map<ShaderDataType, unsigned int> shaderDataTypeSizeMap;
extern const std::unordered_map<ShaderDataType, unsigned int> shaderDataTypeCountMap;
extern const std::unordered_map<ShaderDataType, GLenum> shaderDataTypeToGLTypeMap;
