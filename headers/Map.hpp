//
// Created by Remy Villules on 2019-02-13.
//

#ifndef GAMEOFLIFE_MAP_HPP
#define GAMEOFLIFE_MAP_HPP

class Map{
public:
    Map(){};
    void setValueAtPosition(const int &y, const int &x, const int &value);
    int const getValueAtPosition(const int &y, const int &x) const;
    void setMap(int**map, const bool& freePreviousMap);
    void deleteMap() const;
    int const getSizeY() const;
    int const getSizeX() const;
    int ** clone() const;
    void initializeMap(const int &sizeY, const int &sizeX);
    void populateMap(const bool &random);
    void printMap() const;
    const int getNewValueForPosition(const int& y, const int& x);

private:
    int** map;
    int sizeX;
    int sizeY;
    int getTopCell(const int& y, const int& x);
    int getBotCell(const int& y, const int& x);
    int getLeftCell(const int& y, const int& x);
    int getRightCell(const int& y, const int& x);
    int getTopRightCell(const int& y, const int& x);
    int getBotRightCell(const int& y, const int& x);
    int getTopLeftCell(const int& y, const int& x);
    int getBotLeftCell(const int& y, const int& x);
};

#endif //GAMEOFLIFE_MAP_HPP
