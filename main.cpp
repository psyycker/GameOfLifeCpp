#include <iostream>
#include "headers/Core.hpp"

int main() {
    Core core;
    core.setIterations(50);
    core.initializeMap(20, 20);
    core.populateMap(true);
    core.printMap();
    return 0;
}