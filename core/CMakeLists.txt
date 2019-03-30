showPathInfos()

add_executable(launcher launcher.cpp)
add_executable(main main.cpp)

target_link_libraries(main PRIVATE module1)