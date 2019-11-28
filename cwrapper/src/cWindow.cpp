#include "cWindow.h"

#include "../engine/src/Window.h"

extern "C" {
void SetTitle(cWindow cwindow, const char *title) {

    auto window = (Atlas::Window *) cwindow;
    window->SetTitle(title);

}

void Clear(cWindow cwindow, float x, float y, float z) {

    auto window = (Atlas::Window *) cwindow;
    auto vec = vec3(x, y, z);
    window->Clear(vec);

}
}