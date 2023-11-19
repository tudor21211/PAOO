cmake_minimum_required(VERSION 3.12)
Project(Telefon VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_subdirectory(Device)
add_subdirectory(AndroidDevice)
add_subdirectory(Tablet)
add_subdirectory(Smartphone)




