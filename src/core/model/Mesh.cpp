#include "core/model/Mesh.h"
#include "core/opengl/OpenGLAPI.h"

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices, const std::vector<std::shared_ptr<Texture>> &textures)
    : vertices(vertices), indices(indices), textures(textures)
{
    setupMesh();
}

void Mesh::draw(Shader& shader)
{
    for(unsigned int i = 0; i < textures.size(); i++)
    {
        shader.setInt(("texture_diffuse" + std::to_string(i)).c_str(), i);
        textures[i]->bind(i);
    }
    
    OpenGLAPI::draw(vao.get());
}

void Mesh::setupMesh()
{
    vao = std::make_unique<VAO>();

    std::shared_ptr<VBO> vbo = std::make_shared<VBO>(vertices.data(), sizeof(Vertex) * vertices.size());
    vbo->setLayout({{ShaderDataType::Vec3, false},
                    {ShaderDataType::Vec3, false},
                    {ShaderDataType::Vec2, false}});

    std::shared_ptr<EBO> ebo = std::make_shared<EBO>(indices.data(), indices.size());

    vao->addVBO(vbo);
    vao->setEBO(ebo);
}
