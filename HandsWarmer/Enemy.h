#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(); // Default constructor
    void setTexture(const sf::Texture& texture); // Method to set the texture
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);
    void seePlayer();
    static sf::Sprite sprite;

private:
    sf::Vector2f velocity;
    float speed; // How fast the player moves
    float gravity; // Gravity value
};

#endif // ENEMY.H
