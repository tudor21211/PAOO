add_library(androidDevice STATIC AndroidDevice.cpp)
target_link_libraries(androidDevice PUBLIC smartphone)
target_include_directories(androidDevice PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(androidDevice PUBLIC "${PROJECT_SOURCE_DIR}/Smartphone")