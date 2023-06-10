//
// Created by Slope on 6/10/23.
//

#include "spdlog/spdlog.h"
#include "../include/Application.h"
#include "../include/gl_context.h"
#include "../include/ShaderSource.h"

Application* Application::m_instance = nullptr;

Application *Application::getInstance() {
    if(!m_instance){
        m_instance = new Application();
    }
    return m_instance;
}

Application::Application() {
    m_running = true;
    m_window = nullptr;
    m_VAO = 0;
    m_VBO = 0;
    m_EBO = 0;
    m_program = 0;
    m_statusError = 0;
}

bool Application::isRunning() const {
    return m_running && !m_window->shouldClose();
}


void Application::setup() {

    glfwSetErrorCallback([](int, const char* error){
        spdlog::error(error);
    });

    if(!glfwInit())
    {
        spdlog::critical("Could not initialize GLFW");
        m_running = false;
        setErrorStatus();
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    m_window = new Window("OpenGL Window", 800, 600);

    if(!m_window->create())
    {
        m_running = false;
        setErrorStatus();
        return;
    }

    /**
     * Shader
     */
    uint32_t vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &ShaderSource::vertex, nullptr);
    glCompileShader(vShader);

    int success;
    char info[512];
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vShader, 512, nullptr, info);
        spdlog::error(info);
        return;
    }

    uint32_t fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &ShaderSource::fragment, nullptr);
    glCompileShader(fShader);

    glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fShader, 512, nullptr, info);
        glDeleteShader(vShader);
        spdlog::error(info);
        m_running = false;
        return;
    }

    m_program = glCreateProgram();
    glAttachShader(m_program, vShader);
    glAttachShader(m_program, fShader);
    glLinkProgram(m_program);

    glGetProgramiv(m_program, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(m_program, 512, nullptr, info);
        glDeleteShader(vShader);
        glDeleteShader(fShader);
        spdlog::error("Could not link shader m_program");
        m_running = false;
        return;
    }

    glDeleteShader(vShader);
    glDeleteShader(fShader);

    /**
     * Shapes
     */
    float vertices[] = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left
    };
    unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3
    };

    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Application::destroy() {
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
    glDeleteProgram(m_program);
    m_window->destroy();
    delete m_window;
    glfwTerminate();
}

void Application::update() {
}

void Application::render() const {
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(m_program);
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void Application::processInput() {
    m_window->processInput();
}

void Application::setupNextFrame() {
    m_window->swapBuffer();
    glfwPollEvents();

    if (!m_running && m_window->shouldClose()){
        m_window->setShouldClose(true);
    }
}

void Application::setErrorStatus() {
    m_statusError = 1;
}

int Application::getErrorStatus() const {
    return m_statusError;
}
