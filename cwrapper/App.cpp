#include "App.h"
#include "../go/app.h"

#include <windows.h>

std::string Atlas::EngineInstance::assetDirectory = "../data";
std::string Atlas::EngineInstance::shaderDirectory = "shader";

void App::LoadContent() {

	libWrapper = LibraryWrapper("../go/App.so");

    GoLoadContent = (void (*)())libWrapper.GetFunction("LoadContent");
    GoUnloadContent = (void (*)())libWrapper.GetFunction("UnloadContent");
    GoUpdate = (void (*)(float))libWrapper.GetFunction("Update");
    GoRender = (void (*)(float))libWrapper.GetFunction("Render");

    GoLoadContent();

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