#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "Log.h"
#include "GameProperties.h"

class Movement {
private:
    Log log;
public:
    sf::Sprite& enemySprite;

    float velocityX;
    float velocityY;
    float additionalMovementSpeed;

    ///////////////
    // FUNCTIONS //
    ///////////////

    Movement(sf::Sprite& enemySprite_c);
    
    void move(const sf::Sprite& enemySprite, float velocityX, float velocityY, sf::Vector2f windowBorders,
        float additionalMovementSpeed = 0.0f);
};

#endif // MOVEMENT_H
