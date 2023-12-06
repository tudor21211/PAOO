cmake_minimum_required(VERSION 3.20)

project(MyProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_subdirectory(libs) 
find_package(Threads REQUIRED)


add_executable(main_executable main.cpp)
target_link_libraries(main_executable PRIVATE Threads::Threads Items)



