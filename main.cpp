#include <iostream>
#include "headers/Core.hpp"

int main() {
    Core core;
    core.setIterations(50);
    core.startGameOfLife(20, 20);
    return 0;
}