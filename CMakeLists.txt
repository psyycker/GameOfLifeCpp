cmake_minimum_required(VERSION 3.13)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameOfLife main.cpp src/Core.cpp headers/Core.hpp src/ThreadManager.cpp headers/ThreadManager.hpp src/Map.cpp headers/Map.hpp src/Ui.cpp headers/Ui.hpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(GameOfLife ${SFML_LIBRARIES})
endif()