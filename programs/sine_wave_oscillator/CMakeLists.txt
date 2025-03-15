set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Programs)

add_executable(sine_wave_oscillator main.c)

target_link_libraries(sine_wave_oscillator ${MATH_LIB})

install(TARGETS sine_wave_oscillator)
