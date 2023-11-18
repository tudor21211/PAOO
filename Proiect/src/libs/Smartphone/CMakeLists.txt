add_library(smartphone STATIC Smartphone.cpp )

target_link_libraries(smartphone PUBLIC device)

target_include_directories(smartphone PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(smartphone PUBLIC "${PROJECT_SOURCE_DIR}/Device")