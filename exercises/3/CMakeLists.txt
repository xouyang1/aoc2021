get_filename_component(project_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB source_files *.cpp)

add_executable(${project_name}
    ${source_files}
)

target_link_libraries(${project_name} PUBLIC
    utils
)

set_target_properties(${project_name} 
    PROPERTIES 
        SUFFIX ".out" 
        OUTPUT_NAME ${project_name}
)