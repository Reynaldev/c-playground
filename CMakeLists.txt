cmake_minimum_required(VERSION 3.30)
project(c_playground)

set(CMAKE_C_STANDARD 11)

find_library(MATH_LIB m)

add_subdirectory(basic)
add_subdirectory(multithreading)
add_subdirectory(opencl)
add_subdirectory(programs/CLinkedList)
add_subdirectory(programs/DynarC)
add_subdirectory(programs/sine_wave_oscillator)
add_subdirectory(programs/txa)
