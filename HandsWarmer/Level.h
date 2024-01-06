#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>

class Level {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
public:
    Level();
    bool load(const std::string& backgroundTexturePath);
    void render(sf::RenderWindow& window);
};
#endif // LEVEL_H
