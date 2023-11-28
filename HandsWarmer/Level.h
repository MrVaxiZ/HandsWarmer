#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>

class Level {
public:
    Level();
    bool load(const std::string& backgroundTexturePath);
    void render(sf::RenderWindow& window);

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};

#endif // LEVEL_H
