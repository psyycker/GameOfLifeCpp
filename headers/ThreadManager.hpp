//
// Created by Remy Villules on 2019-02-13.
//

#ifndef GAMEOFLIFE_MAPMANIPULATOR_HPP
#define GAMEOFLIFE_MAPMANIPULATOR_HPP

#include "Map.hpp"

class ThreadManager {
public:
    ThreadManager(const int& calcThreadNumber, const int&displayThreadNumber);
    void start(Map* map);
private:
    int calcThreadNumber;
    int displayThreadNumber;
};

#endif //GAMEOFLIFE_MAPMANIPULATOR_HPP
