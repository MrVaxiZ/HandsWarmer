#ifndef SHOOTER_H
#define SHOOTER_H

#include "Log.h"  // Include if needed for logging
#include <SFML/Graphics.hpp>
#include <vector>

class Shooting {
public:
    Shooting(float shootingDelay, const sf::Texture& texture, const sf::Sprite& userS);

    void setShootingDelay(float delay);
    void setTexture(const sf::Texture& texture);
    void shoot(sf::Vector2f position, sf::Vector2f direction);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);  // Method to draw projectiles

private:
    float shootingDelay;  // Delay between shots
    sf::Texture texture_v;  // Texture for the projectiles
    sf::Sprite user;  // User sprite, if needed
    sf::Time timeSinceLastShot;  // Time elapsed since the last shot
    int currentAmmo;  // Ammo count
    float projectileSpeed;  // Speed of the projectiles

    // Store projectiles as pairs of position and direction
    std::vector<std::pair<sf::Vector2f, sf::Vector2f>> projectiles;
};

#endif // SHOOTER_H
