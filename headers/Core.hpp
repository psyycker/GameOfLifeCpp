//
// Created by Remy Villules on 2019-02-13.
//

#ifndef GAMEOFLIFE_CORE_HPP
#define GAMEOFLIFE_CORE_HPP

#include "./Map.hpp"
#include "./ThreadManager.hpp"

class Core{
public:
    Core();
    void setIterations(const int& iterations);
    const int getIterations();
    void initGameOfLife(const int& sizeY, const int&sizeX);
    void startGameOfLife();
    void iterateGameOfLife();
    Map& getMap();

private:
    int iterations;
    Map map;
};

#endif //GAMEOFLIFE_CORE_HPP
