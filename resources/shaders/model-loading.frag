#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec2 TexCoords;

uniform sampler2D texture_diffuse0;

void main()
{    
    FragColor = texture(texture_diffuse0, TexCoords);
}