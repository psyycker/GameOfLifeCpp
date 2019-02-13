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

int const Map::getValueAtPosition(const int &y, const int &x) const {
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
        if (y > 0) {
        }
        for (int x = 0; x < this->getSizeX(); x++) {
            if (random) {
                this->setValueAtPosition(y, x, dis(gen));
            } else {
                this->setValueAtPosition(y, x, 0);
            }
        }
    }
}

int ** Map::clone() const {
    int **newMap = doubleMalloc(this->sizeY, this->sizeX);
    for (int y = 0; y < this->getSizeY(); y++) {
        for (int x = 0; x < this->getSizeX(); x++) {
            newMap[y][x] = this->map[y][x];
        }
    }
    return newMap;
}

void Map::setMap(int **map, const bool &freePreviousMap) {
    if (freePreviousMap) {
        this->deleteMap();
    }
    this->map = map;
}

void Map::deleteMap() const {
    for (int y = 0; y < this->sizeY; y++){
        delete this->map[y];
    }
    delete this->map;
}

int const Map::getSizeY() const {
    return this->sizeY;
}

int const Map::getSizeX() const {
    return this->sizeX;
}


void Map::printMap() const {
    for (int y = 0; y < this->getSizeY(); y++) {
        for (int x = 0; x < this->getSizeX(); x++) {
            std::cout << this->getValueAtPosition(y, x);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

const int computeValue(const int& value, const int& currentValue) {
    if (currentValue == 0) {
        if (value == 3) {
            return 1;
        }
    } else {
        if (value > 3) {
            return 0;
        } else if (value == 2 || value == 3) {
            return 1;
        } else if (value < 2) {
            return 0;
        }
    }
    return currentValue;
}

const int Map::getNewValueForPosition(const int &y, const int &x) {
    int counter = getTopCell(y, x);
    counter += getBotCell(y, x);
    counter += getBotCell(y, x);
    counter += getLeftCell(y, x);
    counter += getRightCell(y, x);
    counter += getTopLeftCell(y, x);
    counter += getTopRightCell(y, x);
    counter += getBotLeftCell(y, x);
    counter += getBotRightCell(y, x);

    return computeValue(counter, getValueAtPosition(y, x));
}

int Map::getBotCell(const int &y, const int &x) {
    int tempY = y + 1;
    if (tempY > this->sizeY - 1) {
        return 0;
    }
    return getValueAtPosition(tempY, x);
}

int Map::getTopCell(const int &y, const int &x) {
    int tempY = y - 1;
    if (tempY < 0) {
        return 0;
    }
    return getValueAtPosition(tempY, x);
}

int Map::getLeftCell(const int &y, const int &x) {
    int tempX = x - 1;
    if (tempX < 0) {
        return 0;
    }
    return getValueAtPosition(y, tempX);
}

int Map::getRightCell(const int &y, const int &x) {
    int tempX = x + 1;
    if (tempX > sizeX - 1) {
        return 0;
    }
    return getValueAtPosition(y, tempX);
}

int Map::getTopRightCell(const int &y, const int &x) {
    int tempX = x + 1;
    int tempY = y - 1;
    if (tempX > sizeX - 1 || tempY < 0) {
        return 0;
    }
    return getValueAtPosition(y, tempX);
}

int Map::getBotRightCell(const int &y, const int &x) {
    int tempX = x + 1;
    int tempY = y + 1;
    if (tempX > sizeX - 1 || tempY > sizeY) {
        return 0;
    }
    return getValueAtPosition(y, tempX);
}

int Map::getTopLeftCell(const int &y, const int &x) {
    int tempX = x - 1;
    int tempY = y - 1;
    if (tempX < 0 || tempY < 0) {
        return 0;
    }
    return getValueAtPosition(y, tempX);
}

int Map::getBotLeftCell(const int &y, const int &x) {
    int tempX = x - 1;
    int tempY = y + 1;
    if (tempX < 0 || tempY > sizeY) {
        return 0;
    }
    return getValueAtPosition(y, tempX);
}



