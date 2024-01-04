#ifndef MECHTROOPER_H
#define MECHTROOPER_H

#include "Enemy.h"
#include "EnemyShooting.h"
#include "Log.h"

class MechTrooper : public Enemy {
private:
    Log log;
    Bullet bullet;
    Magazine magazine;
    EnemyShooting enemyShooting;
    sf::Sprite sprite;
    sf::Vector2f hitBox;
    float distance_p = 200.0f;  // Distance for player detection

public:
    sf::Texture bulletTexture;

    MechTrooper(int hp, int speed, int damage);

    // Override methods
    void attack(const sf::Sprite& player) override;
    void update(sf::Time deltaTime, const sf::Sprite& player);
    void render(sf::RenderWindow& window);
    void setTexture(const sf::Texture& texture);
};

#endif  // MECHTROOPER_H
