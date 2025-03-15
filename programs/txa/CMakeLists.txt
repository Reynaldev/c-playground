set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Programs)

add_executable(txa main.c)

install(TARGETS txa)
