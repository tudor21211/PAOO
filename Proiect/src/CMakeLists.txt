cmake_minimum_required(VERSION 3.11)

project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_subdirectory(libs) 

add_executable(main_executable main.cpp)
target_link_libraries(main_executable device tablet smartphone androidDevice) 


