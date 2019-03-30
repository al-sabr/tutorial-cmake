set(CMAKE_MINIMUM_REQUIRED_VERSION 3.1)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(BITS 64)
else(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(BITS 32)
endif()

include(cmake/DebugVariables.cmake)

cmake_minimum_required(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

set(PROJECT_VERSION 0.0.1)
set(PROJECT_NAME tutorial-cmake)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

showInitialProjectInfos()
showPathInfos()

add_subdirectory(modules)
add_subdirectory(core)

