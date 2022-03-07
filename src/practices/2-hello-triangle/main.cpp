#include "core/core.h"

int main()
{
    Window window = Window();

    const float positions[18] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
    glEnableVertexAttribArray(0);

    while (!window.isClosed())
    {
        window.clear();

        /* Render comes here. */
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.update();
    }

    return 0;
}