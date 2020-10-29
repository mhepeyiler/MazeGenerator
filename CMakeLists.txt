cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(MazeGenerator)
include_directories(inc)
add_executable(MazeGenerator main.cpp   src/RecursiveDivision.cpp
                                        src/BinaryTree.cpp
                                        src/Grid.cpp)