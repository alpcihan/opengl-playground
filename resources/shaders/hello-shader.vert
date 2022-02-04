#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
uniform float uTime;

out vec3 vertexColor;

    void main()
    {
        float offset = 0.5*sin(uTime);
        gl_Position = vec4(offset+aPos, 1.0);
        vertexColor = aColor;
    }
