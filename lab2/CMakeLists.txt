

cmake_minimum_required (VERSION 3.10)

set(myproject "Tutorial")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file (TutorialConfig.h.in TutorialConfig.h)
 
add_executable(${PROJECT_NAME} tutorial.cxx)

target_include_directories ("${PROJECT_BINARY_DIR}")
