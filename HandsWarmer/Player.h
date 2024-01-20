#ifndef PLAYER_H
#define PLAYER_H

#include "Log.h"
#include "Bullet.h"
#include "Magazine.h"

#include <SFML/Graphics.hpp>

#include <vector>

class Player {
private:
    Log log;
public:
    bool isAlive; // Defines whether player is alive

    sf::Vector2f velocity; // Base velocity of a player
    sf::Vector2f jumpVelocity; // Velocity applied when jumping
    bool isOnGround; // Flag to check if the player is on the ground
    bool leftJump; // Flag to determine whether player is jumping left
    bool rightJump; // Flag to determine whether player is jumping right
    float gravity; // Gravity value

    // Ctor values
    float& speed;
    int& dmg;
    int& hp;

    int enemyHp;
    bool shouldMechTrooperBeAlive;

    // Shooting mechanics variables
    sf::Texture bulletTexture;
    Bullet b1;
    Magazine mag;
    std::vector<Bullet> bullets;
    sf::Time timeSinceLastShot = sf::Time::Zero; // Time past since last shot
    sf::Vector2f mousePosWindow;
    sf::Vector2f currVel;
    sf::Vector2f playerCenter;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    float delayBetweenShots; // Amout of time that has to pass in order to add next bullet (seconds)
    float maxSpeed;
    float length;

    // HitBox TODO::Make it more advance to reflect actual shape of texture and to make head
    //               as separete hitbox in order to multiply dmg once it's been hit.
    sf::Vector2f playerHitBox;
    sf::Vector2f enemyHitBox;

    //END Shooting mechanics variables

    Player(float& speed_c, int& dmg_c, int& hp_c); 
    void playerDied();
    void setTexture(const sf::Texture& texture);
    void handleInput();
    void update(sf::Time deltaTime, const sf::Sprite& enemySprite_p, int enemyHp_p);
    void render(sf::RenderWindow& window);
    void getEnemyTrooperHitBox(const sf::Vector2f& enemyHitbox_p);
    void decreaceEnemyHp(int& hp, const int& dmg);
    void enemyDied();

    // Jumping
    void StraightJump();
    void LeftJump();
    void RightJump();

    // Shooting mechanics methodes
    void setMousePos(const sf::Vector2f& window);
    void countShootingTrijectory();
    void infinityAmmo(); // Consider deleting that
    void setBulletTexture(const sf::Texture& texture);
    void bulletCollision(const sf::Sprite& enemySprite_p, sf::Vector2f hitBoxPlayer, sf::Vector2f hitBoxEnemy, int enemyHp);
    // END Shooting mechanics methodes

    static sf::Sprite player_sprite;
};

#endif // PLAYER_H
