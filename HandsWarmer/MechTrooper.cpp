#include "MechTrooper.h"

sf::Sprite MechTrooper::sprite;

// Constructor
MechTrooper::MechTrooper(int hp, int speed, int damage)
    : Enemy(hp, speed, damage), shooter(1.0f, 200.0f) {
    
    shooter.setBulletTexture(bulletTexture);
    name = "MechTrooper";
    sprite.setPosition(100.f, 400.f);
}

bool MechTrooper::detectPlayer(const Player& player, float distance_p)
{
    float playerPosition = player.player_sprite.getPosition().x;
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

sf::Vector2f MechTrooper::normalize(const sf::Vector2f& source)
{
    float length = std::sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
        return sf::Vector2f(source.x / length, source.y / length);
    else
        return source;
}


void MechTrooper::attack()
{
    if (detectPlayer(player, distance_p)) {
        sf::Vector2f direction = player.player_sprite.getPosition() - sprite.getPosition();
        shooter.shoot(sprite.getPosition(), normalize(direction));
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
    shooter.draw(window);
    attack();
}

void MechTrooper::update(sf::Time deltaTime) {
    shooter.update(deltaTime);
    attack();
    Enemy::update(deltaTime);
}
