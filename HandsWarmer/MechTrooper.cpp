#include "MechTrooper.h"

sf::Sprite MechTrooper::sprite;

// Constructor
MechTrooper::MechTrooper(int hp, int speed, int damage)
    : Enemy(hp, speed, damage) {

    name = "MechTrooper";
    sprite.setPosition(100.f, 400.f);
}

void MechTrooper::attack()
{
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

void MechTrooper::render(sf::RenderWindow& window) 
{
    window.draw(sprite);
}

void MechTrooper::update(sf::Time deltaTime) 
{
    detectPlayer(player);
}

void MechTrooper::detectPlayer(const Player& player)
{
    float distance = 200.0f;
    if (player.posX > sprite.getPosition().x + distance)
    {
        log.infoLog("Player X: ", player.posX);
        log.infoLog("Mechtrooper X: ", sprite.getPosition().x);
        log.infoLog("I see you now!");
    }
}

