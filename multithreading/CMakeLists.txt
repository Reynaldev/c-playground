file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)

foreach(source_file ${SOURCE_FILES})
    string(REPLACE ".c" "" target_name ${source_file}) 

    add_executable(${target_name} ${source_file})

    target_link_libraries(${target_name} ${MATH_LIB})

    install(TARGETS ${target_name} DESTINATION bin/multithreading)
    
endforeach(source_file ${SOURCE_FILES})
