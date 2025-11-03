#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Pacmen");
    window.setFramerateLimit(144);

    sf::CircleShape pacman(25.0f);
    pacman.setFillColor(sf::Color(255, 255, 0));

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

        window.draw(pacman);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            pacman.move({0, -5.0f});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            pacman.move({-5.0f, 0});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            pacman.move({0, 5.0f});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            pacman.move({5.0f, 0});
        }

        window.display();
    }
}
