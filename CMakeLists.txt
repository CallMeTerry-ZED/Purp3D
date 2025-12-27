cmake_minimum_required(VERSION 3.10)

project(Purp3D LANGUAGES C CXX)

# -----------------------------
# Platform name
# -----------------------------
if (WIN32)
    set(PURP_PLATFORM "windows")
elseif (APPLE)
    set(PURP_PLATFORM "macos")
elseif (UNIX)
    set(PURP_PLATFORM "linux")
else()
    set(PURP_PLATFORM "unknown")
endif()

# -----------------------------
# Output directories
# -----------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/bin/${PURP_PLATFORM}
)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/lib/${PURP_PLATFORM}
)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/lib/${PURP_PLATFORM}
)

# Visual Studio / multi-config generators
foreach(CONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${CONFIG} CONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG}
        ${CMAKE_BINARY_DIR}/bin/${PURP_PLATFORM}
    )
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONFIG}
        ${CMAKE_BINARY_DIR}/lib/${PURP_PLATFORM}
    )
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONFIG}
        ${CMAKE_BINARY_DIR}/lib/${PURP_PLATFORM}
    )
endforeach()

# -----------------------------
# C++ Standard
# -----------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -----------------------------
# Options
# -----------------------------

# -----------------------------
# Third-party libraries
# -----------------------------
add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/stb)

# -----------------------------
# Source files (GLOB_RECURSIVE)
# -----------------------------
file(GLOB_RECURSE ENGINE_SRC
    engine/src/*.cpp
)

file(GLOB_RECURSE ENGINE_INC
    engine/include/*.h
)

file(GLOB_RECURSE GAME_SRC
    game/src/*.cpp
)

file(GLOB_RECURSE GAME_INC
    game/include/*.h
)

# -----------------------------
# Executable (single EXE for now)
# -----------------------------
add_executable(Purp3D
    ${ENGINE_SRC}
    ${ENGINE_INC}
    ${GAME_SRC}
    ${GAME_INC}
)

set_target_properties(Purp3D PROPERTIES
    OUTPUT_NAME "UntitledGame"
)

# -----------------------------
# Include directories
# -----------------------------
target_include_directories(Purp3D PRIVATE
    engine/include
    game/include
    thirdparty/glfw/include
    thirdparty/glad/include
    thirdparty/glm
    thirdparty/stb/include
)

# -----------------------------
# Link libraries
# -----------------------------
target_link_libraries(Purp3D PRIVATE
    glfw
    glad
    glm
    stb
)

# -----------------------------
# Platform defines
# -----------------------------
if (WIN32)
    target_compile_definitions(Purp3D PRIVATE PURP_PLATFORM_WINDOWS)
elseif (UNIX)
    target_compile_definitions(Purp3D PRIVATE PURP_PLATFORM_LINUX)
endif()

# -----------------------------
# Warnings
# -----------------------------
if (MSVC)
    target_compile_options(Purp3D PRIVATE /W4)
else()
    target_compile_options(Purp3D PRIVATE -Wall -Wextra -Wpedantic)
endif()