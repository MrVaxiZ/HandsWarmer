#include "Movement.h"

Movement::Movement(sf::Sprite& enemySprite_c, float detectionRange_c)
    : enemySprite(enemySprite_c), detectionRange(detectionRange_c) {
}

void Movement::followPlayer(const sf::Sprite& player, sf::Time deltaTime) {
    sf::Vector2f direction = player.getPosition() - enemySprite.getPosition();
    float distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

    if (distance > detectionRange) {
        // Normalize direction and move towards player
        direction /= distance;
        enemySprite.move(direction.x * (deltaTime.asSeconds() * 60), direction.y * deltaTime.asSeconds());
    }
}

void Movement::maintainDistance(const sf::Sprite& player, sf::Time deltaTime) {
    sf::Vector2f direction = enemySprite.getPosition() - player.getPosition();
    float distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

    if (distance < detectionRange) {
        // Normalize direction and move away from player
        direction /= distance;
        enemySprite.move(direction.x * (deltaTime.asSeconds() * 60), direction.y * deltaTime.asSeconds());
    }
}

void Movement::move(float velocityX, float velocityY) {
    enemySprite.move(velocityX, velocityY);
}
