#include "ui.h"
#include <ui/colors.h>


namespace dsv::UI {

UI::UI() = default;

int UI::run() {
    sf::RenderWindow window{{640, 480}, "Penis"};
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
            for (const auto& primitive: primitives_)
                primitive->handleEvent(window, event);
        }
        window.clear(Colors::bgPrimary);
        for (const auto& primitive: primitives_)
            primitive->drawTo(window);
        window.display();
    }
    return 0;
}

UI::~UI() = default;

}// namespace dsv::UI
