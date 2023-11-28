// MousePositionDisplay.h
#ifndef MOUSE_POSITION_DISPLAY_H
#define MOUSE_POSITION_DISPLAY_H

#include <SFML/Graphics.hpp>

class MousePositionDisplay {
public:
    MousePositionDisplay(sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);

private:
    sf::RenderWindow& windowRef;
    sf::Font font;
    sf::Text text;
};

#endif
