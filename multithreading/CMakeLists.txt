set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/multithreading)

file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)

foreach(source_file ${SOURCE_FILES})
    string(REPLACE ".c" "" target_name ${source_file}) 

    add_executable(${target_name} ${source_file})

    if(${target_name} STREQUAL "prime")
        target_link_libraries(${target_name} ${MATH_LIB})
    endif()

    install(TARGETS ${target_name})
    
endforeach(source_file ${SOURCE_FILES})
