// MechTrooper.h
#ifndef MECHTROOPER_H
#define MECHTROOPER_H

#include "Enemy.h"
#include "Log.h"
#include "EnemyShooting.h"

class MechTrooper : public Enemy {
private:
    Log log;
    sf::Sprite sprite;

    Bullet b;
    Magazine mag;

    float distance_p = 200.0f;

public:
    MechTrooper(int hp, int speed, int damage);

    // Override methods
    void attack(const sf::Sprite& player) override;

    // Other
    sf::Vector2f normalize(const sf::Vector2f& source) const;
    void update(sf::Time deltaTime, const sf::Sprite& player);
    void render(sf::RenderWindow& window);
    void setTexture(const sf::Texture& texture);
};

#endif  // MECHTROOPER_H
