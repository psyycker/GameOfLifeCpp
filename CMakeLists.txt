cmake_minimum_required(VERSION 3.13)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameOfLife main.cpp src/Core.cpp headers/Core.hpp src/ThreadManager.cpp headers/ThreadManager.hpp src/Map.cpp headers/Map.hpp)