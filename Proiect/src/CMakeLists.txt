cmake_minimum_required(VERSION 3.12) # You can adjust the version as needed

project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11) # Y

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

add_subdirectory(clasa1) 

add_executable(main_executable main.cpp)
target_link_libraries(main_executable Telefon) 

