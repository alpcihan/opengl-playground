#pragma once

#include "core/shared.h"
#include "core/texture/Texture.h"
#include "core/shader/Shader.h"
#include "core/model/Vertex.h"
#include "core/buffer/VAO.h"
#include "core/buffer/VBO.h"
#include "core/buffer/EBO.h"

class Mesh
{
public:
    // mesh data
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

public:
    Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices, const std::vector<Texture> &textures);
    void draw(Shader& shader);

private:
    std::unique_ptr<VAO> vao;

private:
    void setupMesh();
};