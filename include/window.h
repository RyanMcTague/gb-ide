//
// Created by Slope on 6/10/23.
//

#ifndef GBIDE_WINDOW_H
#define GBIDE_WINDOW_H
#include "gl_context.h"
#include "string"
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
    [[nodiscard]] bool shouldClose() const;
    void swapBuffer();
    void setShouldClose(bool value);
};

#endif //GBIDE_WINDOW_H
