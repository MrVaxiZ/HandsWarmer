#ifndef SHOOTER_H
#define SHOOTER_H

#include "Log.h"
#include <SFML/Graphics.hpp>

class Shooting {
public:
    Shooting(float shootingDelay, const sf::Texture& texture, const sf::Sprite& userS);

    void setShootingDelay(float delay);
    void setTexture(const sf::Texture& texture);
    void shoot(sf::Vector2f position, sf::Vector2f direction);
    void update(sf::Time deltaTime); // Method to update shooting timer

private:
    float shootingDelay; // Delay between shots
    sf::Texture texture_v; // Texture for the projectiles
    sf::Sprite user;
    static sf::Sprite sprite;

    sf::Time timeSinceLastShot; // Time elapsed since the last shot
};

#endif // SHOOTER_H
