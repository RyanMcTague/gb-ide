add_executable(example 
	main.cpp
)

include_directories(acorn PUBLIC ${PROJECT_SOURCE_DIR}/acorn/include)
target_link_libraries(example PRIVATE acorn)