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
    sf::Sprite player_sprite;
    sf::Sprite enemy_sprite;
    sf::Time timeSinceLastShot = sf::Time::Zero; // Time past since last shot
    sf::Vector2f& enemyHitbox;
    sf::Vector2f currVel;
    sf::Vector2f playerCenter;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    sf::CircleShape shape;
    float delayBetweenShots; // Amout of time that has to pass in order to add next bullet (seconds)
    float bulletSpeed;
    float length;
    int& playerDmg;
    int dmg;
    int hp;

    ///////////////
    // FUNCTIONS //
    ///////////////

    // Shooting mechanics
    EnemyShooting(Magazine& mag_c, Bullet& bullet_c, sf::Vector2f& enemyHitbox_c, float delayBetweenShots_c,
        float maxSpeed_c, int& playerDmg, int hp_c, int dmg_c);

    bool playerDetect(const sf::Sprite& player, const sf::Sprite& enemy, float distance);

    void attack(const sf::Sprite& player, const sf::Sprite& enemy, float distance, bool reload, bool infinityAmmo);
    void countShootingTrijectory(const sf::Sprite& player, const sf::Sprite& enemy);
    void bulletCollision(sf::Vector2f hitBoxPlayer, int& playerHp, int& enemyHp);
    void bulletsUpdate(sf::Time deltaTime, const sf::Sprite& player, const sf::Sprite& enemy);
    void bulletsRender(sf::RenderWindow& window);
    void playerDecraseHp(const int& dmg, int& hp);
    void enemyDecraseHp(const int& playerDmg, int& hp);
    void enemyDied();
    void playerDied();
};

#endif // EnemyShooting.h