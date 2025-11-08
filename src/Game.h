#ifndef GAME_H
#define GAME_H

#include <SFML/System/Vector2.hpp>
#include <string>
class Game {
public:
    Game() {};
    Game(sf::Vector2u windowRes, std::string& windowName, int maxFPS) : windowRes(windowRes), windowName(windowName), maxFPS(maxFPS) {};

    void run();

private:
    sf::Vector2u windowRes = {1920, 1080};
    std::string windowName = "Pacmen";
    unsigned int maxFPS = 60;
};

#endif
