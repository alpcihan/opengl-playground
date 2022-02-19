#pragma once

class EBO
{
public:
    EBO(unsigned int *indices, unsigned int indexCount);
    ~EBO();

    void bind() const;
    void unbind() const;

    unsigned int getIndexCount() const;

private:
    unsigned int id;
    unsigned int indexCount;
};
