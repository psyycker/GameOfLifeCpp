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

void Core::initGameOfLife(const int &sizeY, const int &sizeX) {
    this->map = Map();
    std::cout << "Initializing..." << std::endl;
    this->map.initializeMap(sizeY, sizeX);
    std::cout << "Initialized !" << std::endl;
    std::cout << "Populating..." << std::endl;
    this->map.populateMap(true);
    std::cout << "Populated !" << std::endl;
}

/**
 * Will start the whole GoL in parallelism and just return a pointer on the ui queue
 */
void Core::startGameOfLife() {
    ThreadManager manager(8, 2);
    manager.start(&this->map);
}

void Core::iterateGameOfLife() {
    ThreadManager manager(4, 2);
    manager.start(&this->map);
}

Map& Core::getMap() {
    return this->map;
}
