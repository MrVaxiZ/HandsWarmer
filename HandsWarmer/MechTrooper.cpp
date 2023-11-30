#include <iostream>

#include "MechTrooper.h"

#include "Log.cpp"

// Constructor
MechTrooper::MechTrooper(int hp, int speed, int damage)
    : Enemy(hp, speed, damage) {
    
    sprite.setPosition(700, 400);
}

void MechTrooper::setTexture(const sf::Texture& texture)
{
    sprite.setTexture(texture);
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

void MechTrooper::detectPlayer(const Player& player)
{
}

