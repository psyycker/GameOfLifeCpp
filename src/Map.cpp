//
// Created by Remy Villules on 2019-02-13.
//

#include <cstring>
#include <random>
#include <iostream>
#include "../headers/Map.hpp"

void Map::setValueAtPosition(const int &y, const int &x, const int&value) {
    this->map[y][x] = value;
}

int const Map::getValueAtPosition(const int &y, const int &x) {
    return this->map[y][x];
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
void Map::initializeMap(const int &sizeY, const int &sizeX) {
    this->map = doubleMalloc(sizeY, sizeX);
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

/**
 * This wont create the map, just populate it.
 * Use it only if map is generated
 * @param random
 */
void Map::populateMap(const bool &random) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    for (int y = 0; y < this->getSizeY(); y++) {
        for (int x = 0; x < this->getSizeX(); x++) {
            if (random) {
                this->setValueAtPosition(y, x, dis(gen));
            } else {
                this->setValueAtPosition(y, x, 0);
            }
        }
    }
}

int **Map::clone() {
    int **newMap;
}

void Map::setMap(int **map, const bool &freePreviousMap) {
    if (freePreviousMap) {
        this->deleteMap();
    }
    this->map = map;
}

void Map::deleteMap() {
    for (int y = 0; y < this->sizeY; y++){
        delete this->map[y];
    }
    delete this->map;
}

int const Map::getSizeY() {
    return this->sizeY;
}

int const Map::getSizeX() {
    return this->sizeX;
}


void Map::printMap() {
    for (int y = 0; y < this->getSizeY(); y++) {
        for (int x = 0; x < this->getSizeX(); x++) {
            std::cout << this->getValueAtPosition(y, x);
        }
        std::cout << std::endl;
    }
}



