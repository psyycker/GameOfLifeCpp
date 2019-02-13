//
// Created by Remy Villules on 2019-02-13.
//

#ifndef GAMEOFLIFE_CORE_HPP
#define GAMEOFLIFE_CORE_HPP

class Core{
public:
    Core();
    void setIterations(const int& iterations);
    const int getIterations();
    void generateMap(const int& sizeY, const int& sizeX);

private:
    int iterations;
    int **map;
};

#endif //GAMEOFLIFE_CORE_HPP
