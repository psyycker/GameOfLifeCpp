#include <iostream>
#include "../headers/Core.hpp"
//
// Created by Remy Villules on 2019-02-13.
//


Core::Core() {
    std::cout << "hello world" << std::endl;
}

void Core::setIterations(const int &iterations) {
    this->iterations = iterations;
}

const int Core::getIterations() {
    return this->iterations;
}

int ** const doubleMalloc(const int &sizeY, const int &sizeX) {
    int **map = new int*[sizeY];
    for (int y = 0; y < sizeY; y++) {
        map[y] = new int[sizeX];
    }
    return map;
}

void Core::generateMap(const int &sizeY, const int &sizeX) {
    this->map = doubleMalloc(sizeY, sizeX);
}
