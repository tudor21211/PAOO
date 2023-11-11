cmake_minimum_required(VERSION 3.12)
Project(Telefon VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(subproject_sources Telefon.cpp Telefon.hpp)

add_library(Telefon ${subproject_sources})
target_include_directories(Telefon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


