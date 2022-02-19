#pragma once

#include <string>
#include "shader/ShaderType.h"

class Shader
{
public:
    Shader(const std::string &vertexSrcFilePath, const std::string &fragmentSrcFilePath);
    ~Shader();

    void bind() const;

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

private:
    void init(const std::string &vertexSrcFilePath, const std::string &fragmentSrcFilePath);
    std::string readFile(const std::string &shaderSrcFilePath) const;
    unsigned int createShader(const ShaderType shaderType, const char *shaderSource) const;
    void link() const;

    void checkShaderCompileStatus(unsigned int shaderId, const ShaderType shaderType) const;
    void checkProgramLinkStatus() const;

private:
    unsigned int programId;
};