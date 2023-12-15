// MechTrooper.h
#ifndef MECHTROOPER_H
#define MECHTROOPER_H

#include "Enemy.h"
#include "Shooting.h"

class MechTrooper : public Enemy {
private:
    Log log;
    Player player;
    Shooting shooter;

    //Temp to be deleted later
    int64_t bigValue = 0;

    float distance_p = 200.0f;

public:
    MechTrooper(int hp, int speed, int damage);

    // Override methodes
    void takeDamage(int damage) override;
    void attack() override;
    void die() override;

    // Other
    bool detectPlayer(const Player& player, float distance);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);
    void setTexture(const sf::Texture& texture);
    void provideTexture(sf::Texture texture);
};

#endif  // MECHTROOPER_H
