showPathInfos()

add_library(module1 SHARED src/module1.cpp src/module1.h)

target_include_directories(module1 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")