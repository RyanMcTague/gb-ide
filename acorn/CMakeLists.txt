find_package(spdlog REQUIRED)

find_package(glfw3 REQUIRED)

find_package(GLEW REQUIRED)

find_package(glm REQUIRED)

add_library(acorn STATIC
	src/Window.cpp
	src/Application.cpp
	src/Shader.cpp
	src/VertexArrayObject.cpp
	src/VertexBufferObject.cpp
	src/ElementBufferObject.cpp
	src/Scene.cpp
)

include_directories(acorn PUBLIC ${PROJECT_SOURCE_DIR}/acorn/include/acorn)

target_link_libraries(acorn PUBLIC glfw GLEW::GLEW spdlog::spdlog glm::glm)