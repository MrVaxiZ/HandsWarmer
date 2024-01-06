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
    sf::Vector2f velocity; // Base velocity of a player
    sf::Vector2f jumpVelocity; // Velocity applied when jumping
    bool isOnGround; // Flag to check if the player is on the ground
    bool leftJump; // Flag to determine whether player is jumping left
    bool rightJump; // Flag to determine whether player is jumping right
    float gravity; // Gravity value

    // Ctor values
    float speed;
    int dmg;
    int hp;

    // Shooting mechanics
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
    sf::Vector2f HitBox;

    //END Shooting mechanics

    Player(float speed_c, float dmg_c, int hp_c); 
    void setTexture(const sf::Texture& texture);
    void handleInput();
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);

    // Jumping
    void StraightJump();
    void LeftJump();
    void RightJump();

    // Shooting mechanics
    void setMousePos(const sf::Vector2f& window);
    void countShootingTrijectory();
    void infinityAmmo(); // Consider deleting that
    void setBulletTexture(const sf::Texture& texture);
    void bulletCollision(); // not in use currently
    // END Shooting mechanics

    static sf::Sprite player_sprite;
};

#endif // PLAYER_H
