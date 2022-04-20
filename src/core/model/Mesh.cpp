#include "core/model/Mesh.h"
#include "core/opengl/OpenGLAPI.h"

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices)
    : vertices(vertices), indices(indices), textures(textures)
{
    setupMesh();
}

void Mesh::draw()
{
    OpenGLAPI::draw(vao.get());
}

void Mesh::setupMesh()
{
    vao = std::make_unique<VAO>();

    std::shared_ptr<VBO> vbo = std::make_shared<VBO>(vertices.data(), sizeof(float) * 120);
    vbo->setLayout({{ShaderDataType::Vec3, true},
                    {ShaderDataType::Vec2, true}});

    std::shared_ptr<EBO> ebo = std::make_shared<EBO>(indices.data(), sizeof(unsigned int) * 36);

    vao->addVBO(vbo);
    vao->setEBO(ebo);
}
