cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

project(GBIde)

find_package(spdlog REQUIRED)

find_package(glfw3 REQUIRED)

find_package(GLEW REQUIRED)

find_package(glm REQUIRED)

add_executable(GBIde
	acorn/src/main.cpp
	acorn/src/window.cpp
	acorn/src/Application.cpp
	acorn/src/ShaderSource.cpp
	acorn/src/Shader.cpp
)

target_include_directories(GBIde PUBLIC acorn/include)
target_link_libraries(GBIde PRIVATE glfw GLEW::GLEW spdlog::spdlog glm::glm)
