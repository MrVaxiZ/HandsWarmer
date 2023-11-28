#include "Enemy.h"
#include "Log.cpp"

sf::Sprite Enemy::sprite;

Enemy::Enemy() : speed(600.f), gravity(980.f), velocity(sf::Vector2f(0.f, 0.f))
{
    sprite.setPosition(100.f, 400.f);
}

void Enemy::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);
}

void Enemy::update(sf::Time deltaTime) {
    sprite.move(velocity * (deltaTime.asSeconds() * 0.5f));

    if (sprite.getPosition().y > 400.f) {
        sprite.setPosition(sprite.getPosition().x, 400.f);

        velocity.y = 0.f;
        velocity.x = 0.f;
    }

    // Borders for enemy to not leave window
    if (sprite.getPosition().x >= 800.f) {
        sprite.setPosition(720.f, sprite.getPosition().y);
    }
    if (sprite.getPosition().x <= 0.f) {
        sprite.setPosition(1.f, sprite.getPosition().y);
    }
    if (sprite.getPosition().y <= 0.f) {
        sprite.setPosition(sprite.getPosition().x, 1.f);
    }
}

void Enemy::render(sf::RenderWindow& window) {
    // Draw the Enemy
    window.draw(sprite);
}

void Enemy::seePlayer() {

}