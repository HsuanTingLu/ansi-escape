add_executable(showcolor EXCLUDE_FROM_ALL show_color.cpp)

target_include_directories(showcolor
    PUBLIC
        ${PROJECT_SOURCE_DIR}/aesc
)

target_compile_features(showcolor
    PUBLIC
        cxx_std_11
)
set_target_properties(showcolor PROPERTIES
    CXX_EXTENSIONS OFF
)

target_compile_options(showcolor
    PRIVATE
        -Wall
        -Wextra
        -pedantic
        -Werror
)

target_link_libraries(showcolor PRIVATE aesc)
