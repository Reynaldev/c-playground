set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Programs)

add_executable(CLinkedList linked_list.h examples/example.c)

install(TARGETS CLinkedList)
