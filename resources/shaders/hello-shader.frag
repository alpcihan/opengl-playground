#version 330 core

in vec3 vertexColor;
uniform float uTime;

out vec4 FragColor;

void main()
{
    float brightness = abs(sin(uTime));
    FragColor = vec4(brightness*vertexColor, 1.0f);
}