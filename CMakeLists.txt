cmake_minimum_required(VERSION 3.10)

project(Purp3D LANGUAGES C CXX)

# -----------------------------
# C++ Standard
# -----------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

# ---------------------------------------------
# Visual Studio / Multi-Config Generators
# ---------------------------------------------
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
# Options
# -----------------------------
set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "Build spdlog examples" FORCE)
set(SPDLOG_BUILD_EXAMPLE_HO OFF CACHE BOOL "Build spdlog header-only examples" FORCE)
set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "Build spdlog tests" FORCE)
set(SPDLOG_BUILD_TESTS_HO OFF CACHE BOOL "Build spdlog header-only tests" FORCE)
set(SPDLOG_BUILD_BENCH OFF CACHE BOOL "Build spdlog benchmarks" FORCE)

set(SOL2_BUILD_LUA OFF CACHE BOOL "" FORCE)
set(SOL2_LUA_VERSION "5.4" CACHE STRING "" FORCE)
set(SOL2_TESTS OFF CACHE BOOL "" FORCE)
set(SOL2_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SOL2_INTEROP_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SOL2_DYNAMIC_LOADING_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SOL2_DOCS OFF CACHE BOOL "" FORCE)
set(SOL2_SINGLE OFF CACHE BOOL "" FORCE)
set(SOL2_SYSTEM_INCLUDE ON CACHE BOOL "" FORCE)
set(SOL2_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)

# -----------------------------
# Third-party libraries
# -----------------------------
add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/stb)
add_subdirectory(thirdparty/imgui)
add_subdirectory(thirdparty/spdlog)
add_subdirectory(thirdparty/lua)
add_subdirectory(thirdparty/sol2)

set_target_properties(glfw PROPERTIES FOLDER "Thirdparty")
set_target_properties(glad PROPERTIES FOLDER "Thirdparty")
set_target_properties(glm PROPERTIES FOLDER "Thirdparty")
set_target_properties(stb PROPERTIES FOLDER "Thirdparty")
set_target_properties(imgui PROPERTIES FOLDER "Thirdparty")
set_target_properties(spdlog PROPERTIES FOLDER "Thirdparty")
set_target_properties(lua PROPERTIES FOLDER "Thirdparty")
set_target_properties(sol2 PROPERTIES FOLDER "Thirdparty")

# -----------------------------
# Source files
# TODO: DONT DO THIS, FIX ASAP
# -----------------------------
file(GLOB_RECURSE ENGINE_SRC
    engine/src/c*.cpp
    engine/src/*/*.cpp
    engine/src/*/*/*.cpp
    engine/src/*/*/*/*.cpp
    engine/src/*/*/*/*/*.cpp
    engine/src/*/*/*/*/*/*.cpp
    engine/src/*/*/*/*/*/*/*.cpp
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

file(GLOB_RECURSE LUA_SCRIPTS
    game/assets/scripts/*.lua
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


source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${ENGINE_SRC} ${ENGINE_INC} ${GAME_SRC} ${GAME_INC} ${LUA_SCRIPTS})
target_sources(Purp3D PRIVATE ${LUA_SCRIPTS})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Purp3D)
set_target_properties(Purp3D PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:Purp3D>"
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
    thirdparty/imgui
    thirdparty/spdlog/include
    thirdparty/lua
    thirdparty/sol2/include
)

# -----------------------------
# Link libraries
# -----------------------------
target_link_libraries(Purp3D PRIVATE
    glfw
    glad
    glm
    stb
    imgui
    spdlog
    lua
    sol2
)

# -----------------------------
# Link OpenGL libraries
# -----------------------------
if (WIN32)
    target_link_libraries(Purp3D PRIVATE opengl32)
elseif (APPLE)
    find_library(OpenGL_LIBRARY OpenGL)
    target_link_libraries(Purp3D PRIVATE ${OpenGL_LIBRARY})
elseif (UNIX)
    find_package(OpenGL REQUIRED)
    target_link_libraries(Purp3D PRIVATE OpenGL::GL)
endif()

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

# -------------------------------------
# Copy shaders next to the executable
# -------------------------------------
#add_custom_command(
#    TARGET Purp3D
#    POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/shaders
#        $<TARGET_FILE_DIR:Purp3D>/shaders
#)

# -------------------------------------
# Copy assets next to the executable
# -------------------------------------
#add_custom_command(
#    TARGET Purp3D
#    POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/game/assets
#        $<TARGET_FILE_DIR:Purp3D>/assets
#)

# --------------------------------------------
# copy runtime files next to the executable
# --------------------------------------------
add_custom_target(copy_runtime_files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/game/assets
        $<TARGET_FILE_DIR:Purp3D>/assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders
        $<TARGET_FILE_DIR:Purp3D>/shaders
)