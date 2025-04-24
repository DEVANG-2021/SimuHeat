cmake_minimum_required(VERSION 3.10)
project(SimuHeat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include headers
include_directories(${PROJECT_SOURCE_DIR})

# Source files
add_executable(simuheat main.cpp heat_simulation.cpp)

# Test binary
add_executable(test_simulation test_simulation.cpp heat_simulation.cpp)
