cmake_minimum_required(VERSION 3.10)

project(stb LANGUAGES C CXX)

# ---------------------------------------------
# Add STATIC library
# ---------------------------------------------
add_library(stb STATIC
    src/stb_image.cpp
    include/stb/stb_image.h
)

# ---------------------------------------------
# Include directories
# ---------------------------------------------
target_include_directories(stb PUBLIC
    include
)