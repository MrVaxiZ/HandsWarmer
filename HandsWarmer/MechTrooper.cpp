#include "MechTrooper.h"

// Constructor
MechTrooper::MechTrooper(int hp, int speed, int damage)
    : Enemy(hp, speed, damage)
{
    name = "MechTrooper";
    sprite.setPosition(100.f, 400.f);
}

sf::Vector2f MechTrooper::normalize(const sf::Vector2f& source) const
{
    float length = std::sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
        return sf::Vector2f(source.x / length, source.y / length);
    else
        return source;
}

void MechTrooper::attack(const sf::Sprite& player)
{
    //if (detectPlayer(player, distance_p)) {
    //    sf::Vector2f direction = player.getPosition() - sprite.getPosition();
    //}
}

void MechTrooper::update(sf::Time deltaTime, const sf::Sprite& player) {
    Enemy::update(deltaTime);
    attack(player);
}

void MechTrooper::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

void MechTrooper::setTexture(const sf::Texture& texture)
{
    sprite.setTexture(texture);
}
