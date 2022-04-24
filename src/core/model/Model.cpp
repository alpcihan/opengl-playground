#include "core/model/Model.h"

Model::Model(char *path)
{
    loadModel(path);
}

void Model::draw(Shader &shader)
{
    for(auto& mesh: meshes)
    {
        mesh->draw(shader);
    }
}

void Model::loadModel(std::string path)
{
    Assimp::Importer importer;
    path = MODEL_DIR + path;
    const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        spdlog::error(std::string("ERROR::ASSIMP::") + importer.GetErrorString());
        return;
    }

    directory = path.substr(0, path.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene)
{
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

std::shared_ptr<Mesh> Model::processMesh(const aiMesh *mesh, const aiScene *scene)
{
    const std::vector<Vertex> vertices = processVertices(mesh);
    const std::vector<unsigned int> indices = processIndices(mesh);
    const std::vector<std::shared_ptr<Texture>> textures = processMaterials(mesh, scene);

    return std::make_shared<Mesh>(vertices, indices, textures);
}

std::vector<Vertex> Model::processVertices(const aiMesh *mesh)
{
    std::vector<Vertex> vertices;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        glm::vec3 position(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
        spdlog::info("{0} {1}", mesh->mNormals[i].x, mesh->mNormals[i].y);
        glm::vec3 normal(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);
        glm::vec2 texCoords(mesh->mTextureCoords[0]
                                ? glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y)
                                : glm::vec2(0.0f, 0.0f));

        Vertex vertex;
        vertex.position = position;
        vertex.normal = normal;
        vertex.texCoords = texCoords;
        vertices.push_back(vertex);
    }

    return vertices;
}

std::vector<unsigned int> Model::processIndices(const aiMesh *mesh)
{
    std::vector<unsigned int> indices;

    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }

    return indices;
}

std::vector<std::shared_ptr<Texture>> Model::processMaterials(const aiMesh *mesh, const aiScene *scene)
{
    std::vector<std::shared_ptr<Texture>> diffuseMaps;

    if (mesh->mMaterialIndex >= 0)
    {
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE);
    }

    return diffuseMaps;
}

std::vector<std::shared_ptr<Texture>> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type)
{
    std::vector<std::shared_ptr<Texture>> textures;
    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString path;
        mat->GetTexture(type, i, &path);
        std::shared_ptr<Texture> texture = std::make_shared<Texture>(path.C_Str());
        textures.push_back(texture);
    }
    return textures;
}