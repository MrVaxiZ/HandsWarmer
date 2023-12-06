// MechTrooper.h
#ifndef MECHTROOPER_H
#define MECHTROOPER_H

#include "Enemy.h"

class MechTrooper : public Enemy {
private:
    Log log;
    Player player;
public:
    MechTrooper(int hp, int speed, int damage);

    // Override methodes
    void takeDamage(int damage) override;
    void attack() override;
    void die() override;

    // Other
    void detectPlayer(const Player& player);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);
    void setTexture(const sf::Texture& texture);
};

#endif  // MECHTROOPER_H
