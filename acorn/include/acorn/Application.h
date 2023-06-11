#ifndef ACORN_APPLICATION_H
#define ACORN_APPLICATION_H
#include "Window.h"

namespace Acorn{
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
        bool isRunning() const;
        void setup();
        void destroy();
        void update();
        void render() const;
        void processInput();
        void setupNextFrame();
        void setErrorStatus();
        int getErrorStatus() const;
    };
}


#endif
