#include "../include/Application.h"

int main(){
    Application* app = Application::getInstance();

    app->setup();

    while (app->isRunning())
    {
        app->processInput();
        app->update();
        app->render();
        app->setupNextFrame();
    }

    app->destroy();

    int status = app->getErrorStatus();
    delete app;
    return status;
}