cmake_minimum_required(VERSION 3.15)
project(Circumference)

set(CMAKE_CXX_STANDARD 14)

add_executable(Circumference main.cpp)

target_link_libraries(Circumference -lglut -lGL -lGLU)