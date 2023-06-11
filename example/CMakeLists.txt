add_executable(example 
	src/ExampleApplication.cpp
)

include_directories(acorn PUBLIC 
	${PROJECT_SOURCE_DIR}/acorn/include 
	${PROJECT_SOURCE_DIR}/example/include
)
target_link_libraries(example PRIVATE acorn)