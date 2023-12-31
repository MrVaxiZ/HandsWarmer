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
    sf::Vector2f velocity; // Base velocity of a player
    sf::Vector2f jumpVelocity; // Velocity applied when jumping
    bool isOnGround; // Flag to check if the player is on the ground
    bool leftJump; // Flag to determine whether player is jumping left
    bool rightJump; // Flag to determine whether player is jumping right
    float speed; // How fast the player moves
    float gravity; // Gravity value
    float dmg;
    int hp;


    // Shooting mechanics
    Bullet b1;
    Magazine mag;
    std::vector<Bullet> bullets;
    sf::Time timeSinceLastShot = sf::Time::Zero; // Time past since last shot
    sf::Vector2f mousePosWindow;
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

    //END Shooting mechanics
public:
    Player(); 
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

    void bulletCollision(); // not in use currently
    // END Shooting mechanics

    static sf::Sprite player_sprite;
};

#endif // PLAYER_H
