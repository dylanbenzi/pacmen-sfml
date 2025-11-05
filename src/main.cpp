#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>
#include "TileMapLoader.h"
#include "TileMap.h"

int main()
{
    // Load tilemap data from JSON
    TileMapData tilemapData;
    try {
        tilemapData = TileMapLoader::loadFromJSON("util/pacmantiles32.json");
    } catch (const std::exception& e) {
        std::cerr << "Error loading tilemap: " << e.what() << std::endl;
        return -1;
    }

    TileMap map;
    if (!map.load("assets/maze32.png",
                  {tilemapData.tileSize, tilemapData.tileSize},
                  tilemapData.tiles.data(),
                  tilemapData.width,
                  tilemapData.height))
        return -1;

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Pacmen");
    window.setFramerateLimit(144);

    const sf::Font bitFont("assets/PressStart2P.ttf");

    sf::Text currTile(bitFont, "Current Tile: ");
    currTile.move({1000, 50});

    sf::CircleShape pacman(20.0f);
    pacman.setFillColor(sf::Color(255, 255, 0));
    pacman.move({32, 32});

    int x = 0;
    int y = 0;
    
    sf::Text tileX(bitFont, "0");
    tileX.move({1000, 100});

    sf::Text tileY(bitFont, "0");
    tileY.move({1100, 100});

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
        window.draw(currTile);
        window.draw(tileX);
        window.draw(tileY);

        window.draw(pacman);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            pacman.move({0, -5.0f});
            y--;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            pacman.move({-5.0f, 0});
            x--;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            pacman.move({0, 5.0f});
            y++;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            pacman.move({5.0f, 0});
            x++;
        }

        tileX.setString(std::to_string(x));
        tileY.setString(std::to_string(y));

        window.display();
    }
}
