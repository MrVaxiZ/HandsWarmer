#include "Enemy.h"

// Constructor implementation
Enemy::Enemy(int h, int s, int d) : hp(h), speed(s), damage(d) {}

// Set the texture for the sprite
void Enemy::setTexture(const sf::Texture& texture) 
{
    sprite.setTexture(texture);
}

void Enemy::provideTexture(sf::Texture texture) {
    bulletTexture = texture;
};

void Enemy::render(sf::RenderWindow& window) 
{
    window.draw(sprite);
}

void Enemy::update(sf::Time deltaTime) 
{}

// Detect the player
bool Enemy::detectPlayer(const Player& player, float distance) 
{
    float playerPosition = player.player_sprite.getPosition().x;
    float mechPosition = sprite.getPosition().x;

    if (abs(playerPosition - mechPosition) <= distance) {
        return true;
    }
    else {
        return false;
    }
}

// Attack logic
void Enemy::attack() 
{
}

// Dying logic
void Enemy::die() 
{
}

// Take damage and check for death
void Enemy::takeDamage(int damage) {
    hp -= damage;
    if (hp <= 0) {
        die();
    }
}
