#include "Level.h"

Level::Level() {
}

bool Level::load(const std::string& backgroundTexturePath) {
    if (!backgroundTexture.loadFromFile(backgroundTexturePath)) {
        return false; // Loading failed, handle this appropriately
    }
    backgroundSprite.setTexture(backgroundTexture);
    return true;
}

void Level::render(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
}
