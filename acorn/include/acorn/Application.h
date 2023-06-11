#ifndef ACORN_APPLICATION_H
#define ACORN_APPLICATION_H
#include <vector>
#include "Window.h"
#include "Scene.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"
#include "Shader.h"

namespace Acorn{
    class Application {
        bool m_running;
        int m_statusError;
        Window* m_window;
        VertexArrayObject* VAO;
        VertexBufferObject* VBO;
        ElementBufferObject* EBO;
        Shader* shader;

    public:
        Application();
        int run();
    private:
        bool isRunning() const;
        void setup();
        void destroy();
        void update();
        void render();
        void processInput();
        void setupNextFrame();
        void setErrorStatus();
        int getErrorStatus() const;
    };
}


#endif
