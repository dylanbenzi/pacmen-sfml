#ifndef BLINKY_H
#define BLINKY_H

#include "Ghost.h"
#include <SFML/System/Vector2.hpp>

class Blinky : public Ghost {
public:
    void setTargetTile(sf::Vector2i target);

    void setBestMove(Entity& pacman);
};

#endif
