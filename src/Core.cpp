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
    std::cout << "Initializing..." << std::endl;
    this->map.initializeMap(10000, 10000);
    std::cout << "Initialized !" << std::endl;
    std::cout << "Populating..." << std::endl;
    this->map.populateMap(true);
    std::cout << "Populated !" << std::endl;
    //this->map.printMap();
    ThreadManager manager(2, 2);
    manager.start(&this->map);
}
