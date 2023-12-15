#ifndef SHOOTER_H
#define SHOOTER_H

#include "Log.h"

#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <ctime> 
#include <vector>

class Shooting {
private:
    sf::Time timeSinceLastShot = sf::Time::Zero;  // Time elapsed since the last shot
    int currentAmmo = INT16_MAX;  // Ammo count
    float projectileSpeed;  // Speed of the projectiles
    float shootingDelay;  // Delay between shots

    // Store projectiles as pairs of position and direction
    std::vector<std::pair<sf::Vector2f, sf::Vector2f>> projectiles;

public:
    Shooting(float shootingDelay_c, float projectileSpeed_c);

    static sf::Sprite sprite_s;

    void debugVariables(sf::Texture texture_p, sf::Sprite user_p,
         float projectileSpeed_p, float ShootingDelay_p );

    void setBulletTexture(sf::Texture texture_b);
    void setShootingDelay(float delay);
    void shoot(sf::Vector2f position, sf::Vector2f direction);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);  // Method to draw projectiles

};
#endif // SHOOTER_H
