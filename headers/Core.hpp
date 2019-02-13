//
// Created by Remy Villules on 2019-02-13.
//

#ifndef GAMEOFLIFE_CORE_HPP
#define GAMEOFLIFE_CORE_HPP

#include "./Map.hpp"

class Core{
public:
    Core();
    void setIterations(const int& iterations);
    const int getIterations();
    void initializeMap(const int& sizeY, const int& sizeX);
    void populateMap(const bool& random);
    void printMap();

private:
    int iterations;
    Map map;
    int sizeX;
    int sizeY;
};

#endif //GAMEOFLIFE_CORE_HPP
