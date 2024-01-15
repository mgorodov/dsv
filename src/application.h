#include <SFML/Graphics.hpp>
class Application {
public:
    Application();

    void run();

    ~Application();

private:
    sf::RenderWindow window;
};
