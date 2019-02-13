#include <iostream>
#include <random>
#include "../headers/Core.hpp"
//
// Created by Remy Villules on 2019-02-13.
//


Core::Core() {
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

/**
 * Will just create a map and populate it with zeros
 * No random generation is done here
 * @param sizeY
 * @param sizeX
 */
void Core::initializeMap(const int &sizeY, const int &sizeX) {
    this->map = doubleMalloc(sizeY, sizeX);
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

void Core::populateMap(const bool &random) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    for (int y = 0; y < this->sizeY; y++) {
        for (int x = 0; x < this->sizeX; x++) {
            if (random) {
                this->map[y][x] = dis(gen);
            } else {
                this->map[y][x] = 0;
            }
        }
    }
}

void Core::printMap() {
    for (int y = 0; y < this->sizeY; y++) {
        for (int x = 0; x < this->sizeX; x++) {
            std::cout << this->map[y][x];
        }
        std::cout << std::endl;
    }
}
