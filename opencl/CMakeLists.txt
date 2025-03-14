file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)

find_package(OpenCL REQUIRED)

foreach(source_file ${SOURCE_FILES})
    string(REPLACE ".c" "" target_name ${source_file}) 

    add_executable(${target_name} ${source_file})

    target_link_libraries(${target_name} OpenCL::OpenCL)

    install(TARGETS ${target_name} DESTINATION bin/basic)
    
endforeach(source_file ${SOURCE_FILES})
