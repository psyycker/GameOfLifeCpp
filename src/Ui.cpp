//
// Created by Rémy Villulles on 2019-02-13.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../headers/Core.hpp"
#include "../headers/Ui.hpp"

int sizeX = 1800;
int sizeY = 1800;



void drawMap(sf::RenderWindow &window, Map &map) {

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    int counter = 0;
    for (int y = 0; y < map.getSizeY(); y++) {
        for (int x = 0; x < map.getSizeX(); x++) {
            sf::RectangleShape rectangle(sf::Vector2f(sizeX / map.getSizeX(), sizeY / map.getSizeY()));
            rectangle.setPosition(x * (sizeX / map.getSizeX()), y * (sizeY / map.getSizeY()));
            if (map.getValueAtPosition(y, x) == 0) {
                rectangle.setFillColor(sf::Color::Black);
            } else {
                rectangle.setFillColor(sf::Color::White);
            }
            window.draw(rectangle);
            counter++;
        }
    }
    end = std::chrono::system_clock::now();
    long elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished DRAWING at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds << "s\n";

}

void Ui::start() {
// create the window
    sf::RenderWindow window(sf::VideoMode(sizeX, sizeY), "My window");

    Core core;
    core.setIterations(1000);
    core.initGameOfLife(200, 200);
    window.setFramerateLimit(30);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        core.iterateGameOfLife();

        // define a 120x50 rectangle
        // clear the window with black color
        window.clear(sf::Color::Black);

        drawMap(window, core.getMap());
        //sf::RectangleShape rectangle(sf::Vector2f(100, 20));
        //rectangle.setPosition(10, 10);
        //window.draw(rectangle);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }
}

