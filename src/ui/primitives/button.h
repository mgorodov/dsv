#pragma once

#include <SFML/Graphics.hpp>
#include <ui/colors.h>
#include <ui/primitives/base.h>

namespace dsv::UI::Primitives {

class Button : public Base {
public:
    std::function<void(Button*)> onClick;
    struct ButtonParams {
        std::string text;
        sf::Vector2f position;
        sf::Vector2f size{100, 50};
        sf::Color primaryColor{Colors::btnPrimary};
        sf::Color hoverColor{Colors::btnHover};
        sf::Color pressedColor{Colors::btnPressed};
    };

    Button(ButtonParams buttonParams)
        : buttonParams_{std::move(buttonParams)} {
        shape_.setSize(buttonParams_.size);
        shape_.setFillColor(buttonParams_.primaryColor);
        shape_.setPosition(buttonParams_.position);

        text_.setString(buttonParams_.text);
        text_.setCharacterSize(15);
        text_.setFillColor(sf::Color::Black);
        text_.setPosition(buttonParams_.position);
    }

    void handleEvent(const sf::RenderWindow& window, const sf::Event& event) override {
        if (isMouseOver(window)) {
            if (event.type == sf::Event::MouseButtonPressed && lastEventType_ == sf::Event::MouseButtonReleased)
                onClick(this);
            shape_.setFillColor(event.type == sf::Event::MouseButtonPressed ? buttonParams_.pressedColor : buttonParams_.hoverColor);
        } else
            shape_.setFillColor(buttonParams_.primaryColor);
        lastEventType_ = event.type;
    }

    void drawTo(sf::RenderWindow& window) override {
        window.draw(shape_);
        window.draw(text_);
    };

private:
    sf::RectangleShape shape_;
    sf::Text text_;

    ButtonParams buttonParams_;
    sf::Event::EventType lastEventType_ = sf::Event::Closed;

    bool isMouseOver(const sf::RenderWindow& window) {
        const auto [mouseX, mouseY] = sf::Mouse::getPosition(window);
        const auto [btnX, btnY] = shape_.getPosition();
        const auto [width, height] = buttonParams_.size;
        return mouseX > btnX && mouseY > btnY && mouseX < btnX + width && mouseY < btnY + height;
    }
};

}// namespace dsv::UI::Primitives
