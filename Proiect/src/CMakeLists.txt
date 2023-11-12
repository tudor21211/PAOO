cmake_minimum_required(VERSION 3.12)

project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_subdirectory(clasa1) 

add_executable(main_executable main.cpp)
target_link_libraries(main_executable Telefon) 

