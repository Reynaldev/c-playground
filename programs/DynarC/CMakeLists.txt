set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Programs)

add_executable(DynarC main.c)

install(TARGETS DynarC)
