#include "application.h"

#include <SFML/Graphics.hpp>

Application::Application() : window{{1280, 720}, "CMake SFML Project"} {
    window.setFramerateLimit(144);
}

void Application::run() {
    sf::CircleShape shape(100.f);
    shape.setPosition(540, 260);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);)
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.draw(shape);
        window.display();
    }
}

Application::~Application() = default;
