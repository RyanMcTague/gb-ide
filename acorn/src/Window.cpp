#include <spdlog/spdlog.h>
#include "Window.h"
#include "Application.h"
using namespace Acorn;
Window::Window(const std::string& title, int width, int height){
    m_handle = nullptr;
    m_height = height;
    m_width  = width;
    m_title  = title;
}

bool Window::create() {
    m_handle = glfwCreateWindow(m_width, m_height,m_title.c_str() ,nullptr, nullptr);
    if(!m_handle)
    {
        spdlog::critical("Could not create m_window");
        return false;
    }

    glfwMakeContextCurrent(m_handle);

    if(glewInit() != GLEW_OK)
    {
        spdlog::critical("Could not initialize m_window");
        glfwDestroyWindow(m_handle);
        return false;
    }

    glfwSetFramebufferSizeCallback(m_handle, [](GLFWwindow* window, int height, int width){
        glViewport(0, 0, width, height);
    });

    return true;
}

void Window::destroy() {
    glfwDestroyWindow(m_handle);
}

void Window::processInput() {
    if(glfwGetKey(m_handle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_handle, true);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(m_handle);
}

void Window::swapBuffer() {
    glfwSwapBuffers(m_handle);
}

void Window::setShouldClose(bool value) {
    glfwSetWindowShouldClose(m_handle, value);
}
