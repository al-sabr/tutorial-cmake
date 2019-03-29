message(STATUS "========================================================")
message(STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR : ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_LIST_FILE : ${CMAKE_CURRENT_LIST_FILE}")
message(STATUS "CMAKE_CURRENT_LIST_DIR : ${CMAKE_CURRENT_LIST_DIR}")

add_library(module1 SHARED src/module1.cpp src/module1.h)

target_include_directories(module1 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")