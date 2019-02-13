//
// Created by Remy Villules on 2019-02-13.
//

#include "../headers/Map.hpp"

Map::Map(int **map) {
    this->map = map;
}

void Map::setValueAtPosition(const int &y, const int &x, const int&value) {
    this->map[y][x] = value;
}

int const Map::getValueAtPosition(const int &y, const int &x) {
    return this->map[y][x];
}

