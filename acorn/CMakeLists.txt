find_package(spdlog REQUIRED)

find_package(glfw3 REQUIRED)

find_package(GLEW REQUIRED)

find_package(glm REQUIRED)

add_library(acorn STATIC
	src/window.cpp
	src/Application.cpp
	src/ShaderSource.cpp
	src/Shader.cpp
)

include_directories(acorn PUBLIC ${PROJECT_SOURCE_DIR}/acorn/include/acorn)

target_link_libraries(acorn PUBLIC glfw GLEW::GLEW spdlog::spdlog glm::glm)