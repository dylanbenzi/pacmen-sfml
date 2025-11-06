#ifndef MAZECHARACTER_H
#define MAZECHARACTER_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "TileMap.h"

enum class MovementDir {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class MazeCharacter {
public:
    MazeCharacter(sf::Texture texture, int tileSize = 32, int baseMovementSpeed = 0) : tileSize(tileSize), baseMovementSpeed(baseMovementSpeed) {
        sf::Sprite characterSprite(texture);
    };

    MazeCharacter(sf::Texture texture, sf::IntRect boundingRect, int tileSize = 32, int baseMovementSpeed = 0) : tileSize(tileSize), baseMovementSpeed(baseMovementSpeed) {
        sf::Sprite characterSprite(texture, boundingRect);
    };

    void changeDirection(MovementDir dir) {
        switch (dir) {
            case MovementDir::UP:
                veloDir = transformVeloUp;
            case MovementDir::DOWN:
                veloDir = transformVeloDown;
            case MovementDir::LEFT:
                veloDir = transformVeloLeft;
            case MovementDir::RIGHT:
                veloDir = transformVeloRight;
        };
    };


    

private:
    int tileSize = 0;
    int halfTileSize = tileSize / 2;

    sf::Vector2i tilePos;
    sf::Vector2f screenPos;
    sf::Vector2f centerPos = {screenPos.x + halfTileSize, screenPos.y + halfTileSize};
    
    sf::Vector2f velo;
    sf::Vector2i veloDir;

    sf::Vector2i transformVeloUp{0, -1};
    sf::Vector2i transformVeloDown{0, 1};
    sf::Vector2i transformVeloRight{1, 0};
    sf::Vector2i transformVeloLeft{-1, 0};
    
    float baseMovementSpeed = 0;

    TileMap mazeMap;


};

#endif
