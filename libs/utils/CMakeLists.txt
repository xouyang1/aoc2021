set(name "utils")

add_library(${name} INTERFACE)

target_link_libraries(${name} INTERFACE
    fmt
)

target_include_directories(${name} INTERFACE
    .
)

set_target_properties(${name} PROPERTIES LINKER_LANGUAGE CXX)