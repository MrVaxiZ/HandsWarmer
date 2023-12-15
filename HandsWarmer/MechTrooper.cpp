#include "MechTrooper.h"

sf::Sprite MechTrooper::sprite;

// Constructor
MechTrooper::MechTrooper(int hp, int speed, int damage)
    : Enemy(hp, speed, damage), shooter(2000.0f, 200.0f) {
    
    shooter.setBulletTexture(bulletTexture);
    name = "MechTrooper";
    sprite.setPosition(100.f, 400.f);
}

bool MechTrooper::detectPlayer(const Player& player, float distance_p)
{
    float playerPosition = player.sprite.getPosition().x;
    float mechPosition = sprite.getPosition().x;

    if (abs(playerPosition - mechPosition) <= distance_p) {
        bigValue++;
        log.infoLog("Shooting! Bullet: ", bigValue);
        return true;
    }
    else {
        return false;
    }
}

void MechTrooper::provideTexture(sf::Texture texture) {
    bulletTexture = texture;
}

void MechTrooper::attack()
{
    if (detectPlayer(player, distance_p)) {
        sf::Vector2f direction = player.sprite.getPosition() - sprite.getPosition();
        shooter.shoot(sprite.getPosition(), direction);
    }
}

void MechTrooper::die()
{
}

void MechTrooper::takeDamage(int damage)
{
}


void MechTrooper::setTexture(const sf::Texture& texture)
{
    sprite.setTexture(texture);
}

void MechTrooper::render(sf::RenderWindow& window) {
    Enemy::render(window);
    attack();
    shooter.draw(window);
}

void MechTrooper::update(sf::Time deltaTime) {
    Enemy::update(deltaTime);
    attack();
    shooter.update(deltaTime);
}
