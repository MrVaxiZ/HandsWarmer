// MousePositionDisplay.cpp
#include "MousePositionDisplay.h"
#include "Player.h"
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Log.h"

MousePositionDisplay::MousePositionDisplay(sf::RenderWindow& window) : windowRef(window) {
    if (!font.loadFromFile("Textures\\arial.TTF")) {
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
}

void MousePositionDisplay::update() {
    sf::Vector2f pixelPos = Player::sprite.getPosition() ; //sf::Mouse::getPosition(windowRef);
    sf::Vector2f worldPos = pixelPos;

    std::stringstream ss;
    ss << "X: " << worldPos.x << ", Y: " << worldPos.y;
    text.setString(ss.str());
}

void MousePositionDisplay::render(sf::RenderWindow& window) {
    window.draw(text);
}
