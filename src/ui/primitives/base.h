#pragma once

#include <SFML/Graphics.hpp>

namespace dsv::UI::Primitives {

class Base {
public:
    virtual void handleEvent(const sf::RenderWindow& window, const sf::Event& event) = 0;
    virtual void drawTo(sf::RenderWindow& window) = 0;
};

}// namespace dsv::UI::Primitives
