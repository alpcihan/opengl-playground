#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec3 Normal;
out vec2 TexCoords;

uniform mat4 u_mtrx;

void main()
{
    Normal = aNormal;
    TexCoords = aTexCoords;    
    gl_Position = u_mtrx * vec4(aPos, 1.0);
}