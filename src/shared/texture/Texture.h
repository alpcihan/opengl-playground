#pragma once

#include <glad/glad.h>
#include <string>

class Texture
{
public:
    Texture(const std::string &path);
    ~Texture();

    void bind(uint32_t slot = 0);
    void unbind() const;

private:
    unsigned int id;
};