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

find_package(EnTT QUIET)
if (NOT EnTT_FOUND)
    FetchContent_Declare(
            entt
            GIT_REPOSITORY https://github.com/skypjack/entt
            GIT_TAG v3.12.2
    )
    if (NOT EnTT_POPULATED)
        FetchContent_Populate(EnTT)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${EnTT_SOURCE_DIR} ${EnTT_BINARY_DIR})
    endif ()
endif ()
# Our Project
add_executable(2d-rogue-like src/main.cpp)

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