#include "core/texture/Texture.h"

Texture::Texture(const std::string &texturePath)
    : id(0)
{
    int width, height, channels;
    stbi_set_flip_vertically_on_load(1);
    unsigned char *textureData = stbi_load((TEXTURE_DIR + texturePath).c_str(), &width, &height, &channels, 0);

    if (!textureData)
    {
        spdlog::error("Failed to stbi_load a texture (path: {0})", texturePath);
        return;
    }

    GLenum internalFormat, dataFormat;
    if (channels == 3)
    {
        internalFormat = GL_RGB8;
        dataFormat = GL_RGB;
    }
    else if (channels == 4)
    {
        internalFormat = GL_RGBA8;
        dataFormat = GL_RGBA;
    }
    else
    {
        spdlog::error("Invalid texture file format (path: {0})", texturePath);
        return;
    }

    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, textureData);

    this->unbind();
    stbi_image_free(textureData);
}

Texture::~Texture()
{
    glDeleteTextures(1, &id);
}

void Texture::bind(uint32_t slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, this->id);
}

void Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}