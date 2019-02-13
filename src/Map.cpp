//
// Created by Remy Villules on 2019-02-13.
//

#include "../headers/Map.hpp"

Map::Map(int **map, const int&sizeY, const int&sizeX) {
    this->map = map;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

void Map::setValueAtPosition(const int &y, const int &x, const int&value) {
    this->map[y][x] = value;
}

int const Map::getValueAtPosition(const int &y, const int &x) {
    return this->map[y][x];
}



void Map::setMap(int **map, const bool &freePreviousMap) {
    if (freePreviousMap) {
        this->deleteMap();
    }
}

void Map::deleteMap() {
    //for (int y = 0; y < this.)
}

int const Map::getSizeY() {
    return this->sizeY;
}

int const Map::getSizeX() {
    return this->sizeX;
}



