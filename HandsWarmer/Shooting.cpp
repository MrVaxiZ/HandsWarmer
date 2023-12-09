#include "Shooting.h"

sf::Sprite Shooting::sprite;

Shooting::Shooting(float sd, const sf::Texture& txt, const sf::Sprite& userS)
    : shootingDelay(sd), texture_v(txt), user(userS), timeSinceLastShot(sf::Time::Zero) {}

void Shooting::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);
}

void Shooting::setShootingDelay(float delay) {
    shootingDelay = delay;
}

void Shooting::shoot(sf::Vector2f position, sf::Vector2f direction) {
    if (timeSinceLastShot.asSeconds() >= shootingDelay) {
        // Reset the timer
        timeSinceLastShot = sf::Time::Zero;
    }
}

void Shooting::update(sf::Time deltaTime) {
    timeSinceLastShot += deltaTime;
}
