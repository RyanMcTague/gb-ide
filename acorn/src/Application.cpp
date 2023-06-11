#include <spdlog/spdlog.h>
#include "Application.h"
#include "opengl.h"

using namespace Acorn;


const char* vertexShaderSource = R""""(
    #version 330 core
    layout (location = 0) in vec3 aPos;

    void main()
    {
        gl_Position = vec4(aPos, 1.0);
    }
)"""";

const char* fragmentShaderSource = R""""(
    #version 330 core
    out vec4 FragColor;

    void main()
    {
        FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    }
)"""";


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

Application::Application() {
    m_running = true;
    m_window = nullptr;
    m_statusError = 0;
}

int Application::run(){
    setup();

    while (isRunning())
    {
        processInput();
        update();
        render();
        setupNextFrame();
    }

    destroy();

    int status = getErrorStatus();
    return status;
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

    shader = new Shader();
    shader->addShaderSource(GL_VERTEX_SHADER, vertexShaderSource);
    shader->addShaderSource(GL_FRAGMENT_SHADER, fragmentShaderSource);
    shader->compile();

    VAO = new VertexArrayObject(true);
    VBO = new VertexBufferObject(true);
    EBO = new ElementBufferObject(true);


    VAO->bind();
        VBO->bind();
        VBO->addVertices<float>(vertices, 12);

        EBO->bind();
        EBO->addIndices(indices, 6);

        VAO->push<float>(3);

        EBO->unbind();
        VBO->unbind();
    VAO->unbind();
}

void Application::destroy() {
    delete VAO;
    delete VBO;
    delete EBO;
    delete shader;
    m_window->destroy();
    delete m_window;
    glfwTerminate();
}

void Application::update() {
    
}

void Application::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    shader->use();
    VAO->bind();
    EBO->bind();
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
