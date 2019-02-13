//
// Created by Remy Villules on 2019-02-13.
//

#include <thread>
#include <iostream>
#include "../headers/ThreadManager.hpp"

ThreadManager::ThreadManager(const int &calcThreadNumber, const int &displayThreadNumber) {
    this->calcThreadNumber = calcThreadNumber;
    this->displayThreadNumber = displayThreadNumber;
}

void startCalcs(int** clonedMap, Map* map, const int& start, const int& range) {
    for (int y = start; y < range; y++) {
        //std::cout << y << std::endl;
        for (int x = 0; x < map->getSizeX(); x++) {
            clonedMap[y][x] = map->getNewValueForPosition(y,x);
        }
    }
}

int** ThreadManager::start(Map* map) {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    std::cout << "starting..." << std::endl;
    int **cloneMap = map->clone();
    std::thread array[this->calcThreadNumber];
    for (int index = 0; index < calcThreadNumber; index++) {
        std::cout << index * map->getSizeY() / calcThreadNumber << std::endl;
        std::cout << (index + 1) * map->getSizeY() / calcThreadNumber << std::endl;
        array[index] = std::thread(startCalcs, cloneMap, map, index * map->getSizeY() / calcThreadNumber, (index + 1) * map->getSizeY() / calcThreadNumber);
    }
    for (int index = 0; index < calcThreadNumber; index++) {
        array[index].join();
    }
    map->setMap(cloneMap, true);
    end = std::chrono::system_clock::now();
    long elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds << "s\n";
}

