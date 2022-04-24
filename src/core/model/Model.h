#pragma once

#include "core/shared.h"
#include "core/model/Mesh.h"

class Model
{
public:
    Model(char *path);
    void draw(Shader &shader);

private:
    std::vector<std::shared_ptr<Mesh>> meshes;
    std::string directory;

private:
    void loadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    std::shared_ptr<Mesh> processMesh(const aiMesh *mesh, const aiScene *scene);
    std::vector<Vertex> processVertices(const aiMesh *mesh);
    std::vector<unsigned int> processIndices(const aiMesh *mesh);
    std::vector<std::shared_ptr<Texture>> processMaterials(const aiMesh *mesh, const aiScene *scene);
    std::vector<std::shared_ptr<Texture>> loadMaterialTextures(aiMaterial *mat, aiTextureType type);
};