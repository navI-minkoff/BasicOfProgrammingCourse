cmake_minimum_required(VERSION 3.20)
project(1 C)

set(CMAKE_C_STANDARD 11)

add_executable(1 main.c)

add_subdirectory(libs)
target_link_libraries(1 data_structures)
target_link_libraries(1 algorithms)