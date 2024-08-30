add_executable(TanoEngine main.cpp)
target_include_directories(TanoEngine PRIVATE src)

target_compile_definitions(TanoEngine PRIVATE
    $<$<CONFIG:Debug>:
        TANO_DEBUG=1
    >
)