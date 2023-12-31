#include "Enemy.h"

// Constructor implementation
Enemy::Enemy(int h, int s, int d) : hp(h), speed(s), damage(d) {}

// Attack logic
void Enemy::attack(const sf::Sprite& player)
{}

// Dying logic
void Enemy::die() 
{}

// Take damage and check for death
void Enemy::takeDamage(int damage) 
{}

void Enemy::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Enemy::update(sf::Time deltaTime)
{
}

// Set the texture for the sprite
void Enemy::setTexture(const sf::Texture& texture)
{
    sprite.setTexture(texture);
}