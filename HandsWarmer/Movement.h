#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <SFML/Graphics.hpp>
#include "Log.h"
#include "GameProperties.h"

class Movement {
private:
    Log log;
    sf::Sprite& enemySprite;
    float detectionRange;

public:
    Movement(sf::Sprite& enemySprite_c, float detectionRange_c);

    void followPlayer(const sf::Sprite& player, sf::Time deltaTime);
    void maintainDistance(const sf::Sprite& player, sf::Time deltaTime);
    void move(float velocityX, float velocityY);
};

#endif // MOVEMENT_H
