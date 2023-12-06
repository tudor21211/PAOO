cmake_minimum_required(VERSION 3.20)

project(Item)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(subproject_sources Item.cpp Item.hpp Inventory.cpp Inventory.hpp)

add_library(Items ${subproject_sources})
target_include_directories(Items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})