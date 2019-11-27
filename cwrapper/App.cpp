#include "App.h"
#include "../go/app.h"

#include <windows.h>

std::string Atlas::EngineInstance::assetDirectory = "../data";
std::string Atlas::EngineInstance::shaderDirectory = "shader";

void App::LoadContent() {

    viewport = Atlas::Viewport(0, 0, window.GetWidth(), window.GetHeight());

    font = Atlas::Font("font/roboto.ttf", 44, 5);

	GoInt a = 12;
	GoInt b = 13;

	out.append("Here we are. ");

	// AtlasLog("%d", Add(a, b));

    HINSTANCE hGetProcIDDLL = LoadLibrary("../go/app.so");

    if (!hGetProcIDDLL) {
        out.append("Failed to load DLL. ");
        return;
    }
    else {
        out.append("Loading DLL successful. ");
    }

    // resolve function address here
    auto add = (GoInt (*)(GoInt, GoInt))GetProcAddress(hGetProcIDDLL, "Add");
    if (!add) {
        out.append("Couldn't find function. ");
        return;
    }
    else {
        out.append("Loading function worked. ");
    }

    std::string title = "Sum " + std::to_string(a) + " + " +
            std::to_string(b) + " = " + std::to_string(add(a, b));

    out.append(title);

}

void App::UnloadContent() {



}

void App::Update(float deltaTime) {



}

void App::Render(float deltaTime) {

    viewport.Set(0, 0, window.GetWidth(), window.GetHeight());

    std::string text = out;

    float width, height;
    font.ComputeDimensions(text, 1.0f, &width, &height);

    auto x = (float)window.GetWidth() / 2.0f - width / 2.0f;
    auto y = (float)window.GetHeight() / 2.0f - height / 2.0f;

    masterRenderer.textRenderer.Render(&viewport, &font, text,
                                       x, y);

}

Atlas::EngineInstance* GetEngineInstance() {

	return new App();

}