#ifndef GO_WRAPPER_H
#define GO_WRAPPER_H

#include <System.h>
#include <App.h>

class GoWrapper {

public:
    GoWrapper() {}

    GoWrapper(std::string library, App* app);

    GoWrapper& operator=(const GoWrapper& that);

    void LoadContent();

    void UnloadContent();

    void Update(float deltaTime);

    void Render(float deltaTime);

private:
    App* app;

};


#endif