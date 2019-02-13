//
// Created by Remy Villules on 2019-02-13.
//

#ifndef GAMEOFLIFE_MAP_HPP
#define GAMEOFLIFE_MAP_HPP

class Map{
public:
    Map(){};
    Map(int**map);
    void setValueAtPosition(const int &y, const int &x, const int &value);
    int const getValueAtPosition(const int &y, const int &x);

private:
    int** map;
};

#endif //GAMEOFLIFE_MAP_HPP
