//
// Created by Slope on 6/10/23.
//

#ifndef GBIDE_APPLICATION_H
#define GBIDE_APPLICATION_H
#include "window.h"

class Application {
    static Application* m_instance;
    bool m_running;
    int m_statusError;
    uint32_t m_VAO, m_VBO, m_EBO;
    uint32_t m_program;
    Window* m_window;
    Application();
public:
    static Application* getInstance();

    [[nodiscard]] bool isRunning() const;
     void setup();
     void destroy();
     void update();
     void render() const;
     void processInput();
     void setupNextFrame();
     void setErrorStatus();
     [[nodiscard]] int getErrorStatus() const;
};


#endif //GBIDE_APPLICATION_H
