//
// Created by Remy Villules on 2019-02-13.
//

#include <thread>
#include <iostream>
#include "../headers/ThreadManager.hpp"

ThreadManager::ThreadManager(const int &calcThreadNumber, const int &displayThreadNumber) {
    this->calcThreadNumber = calcThreadNumber;
    this->displayThreadNumber = displayThreadNumber;
}

void startCalcs(int** clonedMap, Map* map, const int& start, const int& range) {
    for (int y = start; y < range; y++) {
        for (int x = 0; x < map->getSizeX(); x++) {
            clonedMap[y][x] = map->getNewValueForPosition(y,x);
        }
    }
}

void ThreadManager::start(Map* map) {
    /*
     * Todo : Les threads de calcul vont se lancer et s'arreter sans cesse pour permettre de soumettre une nouvelle map.
     * Les threads d'affichage eux vont tourner en boucle et afficher 1 par 1 les tableaux. Pour eviter les desynchros, ils vont
     * s'attendre entre eux
     */
    int **cloneMap = map->clone();
    map->printMap();
    std::thread test(startCalcs, cloneMap, map, 0, map->getSizeY());
    test.join();
    map->setMap(cloneMap, true);
    map->printMap();
}

