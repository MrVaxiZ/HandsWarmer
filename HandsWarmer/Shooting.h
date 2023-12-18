#ifndef SHOOTER_H
#define SHOOTER_H

#include "Log.h"

#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <ctime> 
#include <vector>

class Shooting {
private:
    Log log;
    sf::Sprite sprite_s;
    sf::Time timeSinceLastShot = sf::Time::Zero;
    int currentAmmo;
    float projectileSpeed;
    float shootingDelay;

    // Store projectiles as pairs of position and direction
    std::vector<std::pair<sf::Vector2f, sf::Vector2f>> projectiles;

public:
    Shooting(float shootingDelay_c, float projectileSpeed_c);

    void debugPrint();

    void setBulletTexture(const sf::Texture& texture_b);
    void shoot(sf::Vector2f position, sf::Vector2f direction);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);  // Method to draw projectiles
    void infinityAmmo();
};
#endif // SHOOTER_H
