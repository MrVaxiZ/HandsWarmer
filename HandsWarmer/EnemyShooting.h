// EnemyShooting.h
#ifndef ENEMYSHOOTING_H
#define ENEMYSHOOTING_H

#include "Log.h"
#include "Bullet.h"
#include "Magazine.h"

#include <vector>

#include <SFML/Graphics.hpp>

class EnemyShooting {
public:
    Log log;
    Magazine& mag;
    Bullet& bullet;
    std::vector<Bullet> bullets;
    std::vector<sf::Texture> textures;
    sf::Time timeSinceLastShot = sf::Time::Zero; // Time past since last shot
    sf::Vector2f currVel;
    sf::Vector2f playerCenter;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    sf::CircleShape shape;
    float delayBetweenShots; // Amout of time that has to pass in order to add next bullet (seconds)
    float maxSpeed;
    float length;

    // HitBox TODO::Make it more advance to reflect actual shape of texture and to make head
    //               as separete hitbox in order to multiply dmg once it's been hit.
    int height;
    int width;

    ///////////////
    // FUNCTIONS //
    ///////////////

    // Shooting mechanics
    EnemyShooting(Magazine& mag_c, Bullet& bullet_c, float delayBetweenShots_c, float maxSpeed_c, float length_c);

    bool detectPlayer(const sf::Sprite& player, const sf::Sprite& enemy, float distance);

    void textureProvideCtor(const sf::Texture& texture);
    void texturesSwap(float time);
    void countShootingTrijectory();
    void infinityAmmo();
    void bulletCollision();
};

#endif // EnemyShooting.h