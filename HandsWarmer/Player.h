#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(); // Default constructor
    void setTexture(const sf::Texture& texture); // Method to set the texture
    void handleInput();
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);
    void StraightJump();
    void LeftJump();
    void RightJump();
    static sf::Sprite sprite;

private:
    sf::Vector2f velocity;
    sf::Vector2f jumpVelocity; // Velocity applied when jumping
    float speed; // How fast the player moves
    float gravity; // Gravity value
    bool isOnGround; // Flag to check if the player is on the ground
    bool leftJump; // Flag to determine whether player is jumping left
    bool rightJump; // Flag to determine whether player is jumping right
    int hp;
};

#endif // PLAYER_H
