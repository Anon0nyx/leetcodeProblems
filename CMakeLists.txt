cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SolutionTest)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(testSolution testSolution.cxx Solution.cxx)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Link libraries (if any)
# target_link_libraries(QuadTreeTest <library_name>)

# Add additional source files if needed
# target_sources(QuadTreeTest PRIVATE additional_file.cpp)
