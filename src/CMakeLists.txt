# Aware this is not optimal, but for now, this will do...
file(GLOB_RECURSE TANO_COMPILE "*.cpp")

add_library(Tano ${TANO_COMPILE})
target_include_directories(Tano PRIVATE .)

target_compile_definitions(Tano PRIVATE
    $<$<CONFIG:Debug>:
        TANO_DEBUG=1
    >
)

target_link_libraries(Tano PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    spdlog
)

