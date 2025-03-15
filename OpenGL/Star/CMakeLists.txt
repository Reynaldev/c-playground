set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/OpenGL)

add_executable(Star main.c glad.c)

target_include_directories(Star PRIVATE ../../includes/)

find_package(glfw3 3.4 REQUIRED)

target_link_libraries(Star glfw)

install(TARGETS Star)
