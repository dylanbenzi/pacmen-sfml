#include "Blinky.h"
#include "Entity.h"
#include "MazeMap.h"
#include <limits>

void Blinky::setTargetTile(sf::Vector2i target) {
    targetTile = target;
}

void Blinky::setBestMove(Entity& pacman) {
    if (!mazeMap) return;

    setTargetTile(pacman.getCurrentMazeTile());

    sf::Vector2i currentTile = getCurrentMazeTile();
    MovementDir currentDir = getCurrentDirection();

    MovementDir bestDirection = MovementDir::STATIC;
    float minDistance = std::numeric_limits<float>::max();

    MovementDir directions[] = {MovementDir::UP, MovementDir::DOWN, MovementDir::LEFT, MovementDir::RIGHT};

    for (MovementDir dir : directions) {
        if ((currentDir == MovementDir::UP && dir == MovementDir::DOWN) ||
            (currentDir == MovementDir::DOWN && dir == MovementDir::UP) ||
            (currentDir == MovementDir::LEFT && dir == MovementDir::RIGHT) ||
            (currentDir == MovementDir::RIGHT && dir == MovementDir::LEFT)) {
            continue;
        }

        if (!mazeMap->entityCanMove(*this, dir)) {
            continue;
        }

        sf::Vector2i nextTile = currentTile;
        switch (dir) {
            case MovementDir::UP:
                nextTile.y -= 1;
                break;
            case MovementDir::DOWN:
                nextTile.y += 1;
                break;
            case MovementDir::LEFT:
                nextTile.x -= 1;
                break;
            case MovementDir::RIGHT:
                nextTile.x += 1;
                break;
            case MovementDir::STATIC:
                break;
        }

        float distance = mazeMap->distanceBetweenTiles(nextTile, targetTile);

        if (distance < minDistance) {
            minDistance = distance;
            bestDirection = dir;
        }
    }

    if (bestDirection != MovementDir::STATIC) {
        queueDirection(bestDirection);
    }
};
