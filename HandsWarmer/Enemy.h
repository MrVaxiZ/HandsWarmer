// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

#include "Player.h"

class Enemy {
protected:
    int hp;
    int speed;
    int damage;
    std::string name;
    sf::Texture bulletTexture;
    sf::Sprite sprite;

public:
    Enemy(int h, int s, int d);
    virtual ~Enemy() {}

    // virtual others
    virtual bool detectPlayer(const Player& player, float distance);

    // virtual voids
    virtual void takeDamage(int damage);
    virtual void attack(const sf::Sprite& player);
    virtual void die();
    virtual void update(sf::Time deltaTime);
    virtual void render(sf::RenderWindow& window);
    virtual void setTexture(const sf::Texture& texture);
    virtual void provideTexture(sf::Texture texture);
};

#endif  // ENEMY_H
