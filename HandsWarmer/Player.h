#ifndef PLAYER_H
#define PLAYER_H

#include "Log.h"
#include "Bullet.h"

#include <SFML/Graphics.hpp>

#include <vector>

class Player {
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
    // END Shooting mechanics

    static sf::Sprite player_sprite;
    
private:
    Log log;
    sf::Vector2f velocity; // Base velocity of a player
    sf::Vector2f jumpVelocity; // Velocity applied when jumping
    float speed; // How fast the player moves
    float gravity; // Gravity value
    bool isOnGround; // Flag to check if the player is on the ground
    bool leftJump; // Flag to determine whether player is jumping left
    bool rightJump; // Flag to determine whether player is jumping right
    int hp;

    // Shooting mechanics
    Bullet b1;
    std::vector<Bullet> bullets;
    sf::Vector2f mousePosWindow;
    sf::Vector2f currVel;
    sf::Vector2f playerCenter;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    sf::CircleShape shape;
    float maxSpeed;
    float length;
    //END Shooting mechanics
};

#endif // PLAYER_H
