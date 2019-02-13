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

void Core::startGameOfLife(const int& sizeY, const int&sizeX) {
    this->map = Map();
    this->map.initializeMap(20, 20);
    this->map.populateMap(true);
    //this->map.printMap();
    ThreadManager manager(2, 2);
    manager.start(&this->map);
}
