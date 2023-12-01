// MechTrooper.h
#ifndef MECHTROOPER_H
#define MECHTROOPER_H

#include "Enemy.h"

class MechTrooper : public Enemy {
public:
    MechTrooper(int hp, int speed, int damage);
    void takeDamage(int damage);
    void setTexture(const sf::Texture& texture);
    void detectPlayer(const Player& player);
    void attack();
    void die();
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);
};

#endif  // MECHTROOPER_H
