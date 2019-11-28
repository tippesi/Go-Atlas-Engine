#include "cWindow.h"

#include "../engine/src/Window.h"

extern "C" {
void SetTitle(cWindow cwindow, const char *title) {

    auto window = (Atlas::Window *) cwindow;
    window->SetTitle(title);

}
}