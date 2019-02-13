//
// Created by Remy Villules on 2019-02-13.
//

#ifndef GAMEOFLIFE_MAP_HPP
#define GAMEOFLIFE_MAP_HPP

class Map{
public:
    Map(){};
    void setValueAtPosition(const int &y, const int &x, const int &value);
    int const getValueAtPosition(const int &y, const int &x);
    void setMap(int**map, const bool& freePreviousMap);
    void deleteMap();
    int const getSizeY();
    int const getSizeX();
    int ** clone();
    void initializeMap(const int &sizeY, const int &sizeX);
    void populateMap(const bool &random);
    void printMap();

private:
    int** map;
    int sizeX;
    int sizeY;
};

#endif //GAMEOFLIFE_MAP_HPP
