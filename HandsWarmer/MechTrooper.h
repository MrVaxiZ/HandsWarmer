// MechTrooper.h
#ifndef MECHTROOPER_H
#define MECHTROOPER_H

#include "Enemy.h"
#include "Player.h"
#include "Log.h"

class MechTrooper : public Enemy {
private:
    Log log;
    sf::Sprite sprite;

    //Debug
    int64_t bigValue = 0;
    //END Debug

    float distance_p = 200.0f;

public:
    MechTrooper(int hp, int speed, int damage);

    // Override methods
    //void takeDamage(int damage) override;
    void attack(const sf::Sprite& player) override;
    //void die() override;

    // Other
    sf::Vector2f normalize(const sf::Vector2f& source) const;
    bool detectPlayer(const sf::Sprite& player, float distance);

    void update(sf::Time deltaTime, const sf::Sprite& player);
    void render(sf::RenderWindow& window);
    void setTexture(const sf::Texture& texture);
    //void provideTexture(const sf::Texture& texture);
};

#endif  // MECHTROOPER_H
