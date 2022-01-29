#include <iostream>
#include "Window.h"

int main()
{
    Window window = Window();

    while(!window.isClosed()) {
        window.clear();

        /* Render comes here. */

        window.update();
    }

    return 0;
}