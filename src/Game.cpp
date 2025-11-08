#include <SFML/Graphics/RenderWindow.hpp>

#include "Game.h"
#include "MazeMap.h"
#include "ResourceManager.h"

void Game::run() {
    ResourceManager resources;
    MazeMap map;

    resources.loadTexture("all_textures", "assets/all_textures.png");

    // resize all_textures to 32px
    resources.resizeTexture("all_textures", 32);
    // Collision data: 1=wall, 0=path
    resources.loadMap("mazeMap", "assets/maze.txt");
    // Pellet data: 0=none, 1=pellet, 2=power
    resources.loadMap("pelletMap", "assets/pellets.txt");

    // Texture layout: [Pellet Maze Image] + gap (16px) + [Base Maze Image]
    // Original: 224px (28*8) + 4px gap at 8px tiles
    // Scaled 4x: 896px (28*32) + 16px gap at 32px tiles
    map.loadMaze(resources.getMazeMap(),
                 resources.getPelletMap(),
                 resources.getTexture("all_textures"),
                 32,
                 {912, 0},
                 {0, 0});

    auto window = sf::RenderWindow(sf::VideoMode(windowRes), windowName);
    window.setFramerateLimit(maxFPS);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(); 

        window.draw(map);

        //window.draw();

        window.display();
    }

};
