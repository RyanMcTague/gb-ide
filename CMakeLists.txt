cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

project(GBIde)

find_package(spdlog REQUIRED)

find_package(glfw3 REQUIRED)

find_package(GLEW REQUIRED)

find_package(glm REQUIRED)

add_executable(GBIde
        include/gl_context.h
        src/main.cpp
        include/window.h
        src/window.cpp
        include/Application.h
        src/Application.cpp
        include/ShaderSource.h
        src/ShaderSource.cpp
        src/Shader.cpp
        include/Shader.h
        )

target_link_libraries(GBIde PRIVATE glfw GLEW::GLEW spdlog::spdlog glm::glm)
