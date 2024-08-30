include (FetchContent)

FetchContent_Declare(
    SPDLOG
    GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
    GIT_TAG "v1.14.1"
)

FetchContent_MakeAvailable(SPDLOG)

message(STATUS "[TANO] Successfully fetched spdlog")

FetchContent_Declare(
    SFML
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG "2.6.1"
)

set(SFML_BUILD_AUDIO FALSE)
set(SFML_BUILD_NETWORK FALSE)
set(BUILD_SHARED_LIBS OFF)

FetchContent_MakeAvailable(SFML)

message(STATUS "[TANO] Successfully fetched SFML")