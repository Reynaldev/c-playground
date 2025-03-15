cmake_minimum_required(VERSION 3.30)
project(c_playground)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_library(MATH_LIB m)

add_subdirectory(basic)
add_subdirectory(multithreading)
add_subdirectory(OpenCL)
add_subdirectory(OpenGL/Star)
add_subdirectory(programs/CLinkedList)
add_subdirectory(programs/DynarC)
add_subdirectory(programs/sine_wave_oscillator)
add_subdirectory(programs/txa)
