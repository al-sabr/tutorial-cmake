function(showInitialProjectInfos)
    message(STATUS "========================================================")
    message(STATUS "CMAKE_SIZEOF_VOID_P : ${CMAKE_SIZEOF_VOID_P}")
    message(STATUS "CMAKE_SYSTEM_NAME : ${CMAKE_SYSTEM_NAME} | CMAKE_SYSTEM_VERSION : ${CMAKE_SYSTEM_VERSION} ${BITS}bits")
    message(STATUS "Project name : ${PROJECT_NAME} | Version : ${PROJECT_VERSION}")
    message(STATUS "PROJECT_SOURCE_DIR : ${PROJECT_SOURCE_DIR}")
    message(STATUS "PROJECT_BINARY_DIR : ${PROJECT_BINARY_DIR}")
    message(STATUS "========================================================")
endfunction()

function(showPathInfos)
    message(STATUS "CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
    message(STATUS "CMAKE_CURRENT_BINARY_DIR : ${CMAKE_CURRENT_BINARY_DIR}")
    message(STATUS "CMAKE_CURRENT_LIST_FILE : ${CMAKE_CURRENT_LIST_FILE}")
    message(STATUS "CMAKE_CURRENT_LIST_DIR : ${CMAKE_CURRENT_LIST_DIR}")
    message(STATUS "CMAKE_CURRENT_LIST_LINE : ${CMAKE_CURRENT_LIST_LINE}")
    message(STATUS "========================================================")
    message(STATUS "")
endfunction()

set(CMAKE_MINIMUM_REQUIRED_VERSION 3.1)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(BITS 64)
else(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(BITS 32)
endif()

cmake_minimum_required(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

set(PROJECT_VERSION 0.0.1)
set(PROJECT_NAME tutorial-cmake)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

showInitialProjectInfos()
showPathInfos()

add_subdirectory(modules)
add_subdirectory(core)

