add_executable(sine_wave_oscillator main.c)

target_link_libraries(sine_wave_oscillator ${MATH_LIB})

install(TARGETS sine_wave_oscillator DESTINATION bin/programs/sine_wave_oscillator)
