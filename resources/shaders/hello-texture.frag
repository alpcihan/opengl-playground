#version 330 core
out vec4 FragColor;

uniform sampler2D u_texture0;
uniform sampler2D u_texture1;    

in vec2 TexCoord;

void main()
{
    FragColor = 0.5f* (texture(u_texture0, TexCoord) + texture(u_texture1, TexCoord));
}