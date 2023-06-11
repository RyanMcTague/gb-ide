#ifndef ACORN_WINDOW_H
#define ACORN_WINDOW_H

#include <string>
#include "opengl.h"

namespace Acorn{
    class Window
    {
        GLFWwindow* m_handle;
        int m_width, m_height;
        std::string m_title;
        public:
        Window(const std::string& title, int width, int height);

        bool create();
        void destroy();
        void processInput();
        bool shouldClose() const;
        void swapBuffer();
        void setShouldClose(bool value);
    };
}

#endif
