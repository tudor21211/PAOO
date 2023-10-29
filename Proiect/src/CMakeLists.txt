cmake_minimum_required(VERSION 3.12)

project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Ensure a clean build folder, create if not exists
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../build)
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/../build)

# Set output directories for executables, libraries, etc.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(clasa1) 

add_executable(main_executable main.cpp)
target_link_libraries(main_executable Telefon) 

