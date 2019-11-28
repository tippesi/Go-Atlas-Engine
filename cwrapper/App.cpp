#include "App.h"

#include <windows.h>

std::string Atlas::EngineInstance::assetDirectory = "../data";
std::string Atlas::EngineInstance::shaderDirectory = "shader";

void App::LoadContent() {

	libWrapper = LibraryWrapper("../go/App.so");

    GoLoadContent = (void (*)(cWindow))libWrapper.GetFunction("LoadContent");
    GoUnloadContent = (void (*)())libWrapper.GetFunction("UnloadContent");
    GoUpdate = (void (*)(float))libWrapper.GetFunction("Update");
    GoRender = (void (*)(float))libWrapper.GetFunction("Render");

    GoLoadContent((cWindow)&window);

}

void App::UnloadContent() {

    GoUnloadContent();

}

void App::Update(float deltaTime) {

    GoUpdate(deltaTime);

}

void App::Render(float deltaTime) {

    GoRender(deltaTime);

}

Atlas::EngineInstance* GetEngineInstance() {

	return new App();

}