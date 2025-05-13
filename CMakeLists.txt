cmake_minimum_required(VERSION 3.10)
project(SpaceInvaders)

# Use C++17 or newer
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Set source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# Add executable
add_executable(SpaceInvaders ${SOURCES})

# Include directories (optional if headers are next to .cpp)
target_include_directories(SpaceInvaders PRIVATE include)

# Link SFML
target_link_libraries(SpaceInvaders sfml-graphics sfml-window sfml-system sfml-audio)

