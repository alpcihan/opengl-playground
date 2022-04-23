#pragma once

#include "core/shared.h"
#include "core/model/Mesh.h"

class Model
{
public:
    Model(char *path);
    void draw(Shader &shader);

private:
    std::vector<Mesh> meshes;
    std::string directory;

private:
    void loadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(const aiMesh *mesh, const aiScene *scene);
    std::vector<Vertex> processVertices(const aiMesh *mesh);
    std::vector<unsigned int> processIndices(const aiMesh *mesh);
    std::vector<Texture> processMaterials(const aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type);
};