#version 330 core
out vec4 FragColor;

uniform sampler2D u_texture;  

in vec2 TexCoord;

void main()
{
    FragColor = texture(u_texture, TexCoord).rgba;
}