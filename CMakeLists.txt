cmake_minimum_required(VERSION 3.27)
project(2d-rogue-like)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(FetchContent)

# Dependencies
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif ()
endif ()

find_package(entt QUIET)
if (NOT entt_FOUND)
    FetchContent_Declare(
            entt
            GIT_REPOSITORY https://github.com/skypjack/entt
            GIT_TAG v3.12.2
    )

    if (NOT entt_POPULATED)
        FetchContent_Populate(entt)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${entt_SOURCE_DIR} ${entt_BINARY_DIR})
    endif ()
endif ()
# Our Project
add_executable(2d-rogue-like
        src/main.cpp
        src/core/app.hpp
        src/core/app.cpp
        src/components/position.hpp
        src/components/velocity.hpp
        src/components/size.hpp
        src/components/speed.hpp
        src/core/game.cpp
        src/core/game.hpp
        src/components/player.hpp
        src/factories/player_factory.hpp
        src/core/constants.hpp
        src/services/player_component_service.cpp
        src/services/player_component_service.hpp
        src/components/hit_points.hpp
        src/factories/projectile_factory.hpp
        src/components/projectile.hpp
)

target_link_libraries(${PROJECT_NAME} raylib EnTT::EnTT)

target_include_directories(2d-rogue-like
        PRIVATE
        "${CMAKE_SOURCE_DIR}/src"
)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_OSX_ARCHITECTURES "arm64")
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()