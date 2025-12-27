cmake_minimum_required(VERSION 3.10)

project(glad LANGUAGES C CXX)

# ---------------------------------------------
# Add STATIC library
# ---------------------------------------------
add_library(glad STATIC
    src/gl.c
)

# ---------------------------------------------
# Include directories
# ---------------------------------------------
target_include_directories(glad PUBLIC
    include
)

# ---------------------------------------------
# Set C standard
# ---------------------------------------------
target_compile_features(glad PUBLIC c_std_99)
