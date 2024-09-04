add_executable(TanoTest main.cpp TestGame.cpp TestScene.cpp)
target_link_directories(TanoTest PRIVATE ${CMAKE_BINARY_DIR}/lib)
target_include_directories(TanoTest PRIVATE ${TANO_DIRECTORY} ${TANO_INCLUDE})
target_link_libraries(TanoTest PUBLIC Tano sfml-graphics sfml-window sfml-system spdlog)

# Allow Debug.hpp features to function outside of the Engine project
target_compile_definitions(TanoTest PRIVATE
    $<$<CONFIG:Debug>:
        TANO_DEBUG=1
    >
)