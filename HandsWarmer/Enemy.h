// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Player.h"

class Enemy {
protected:
    int hp;
    int speed;
    int damage;
    std::string name;
    static sf::Sprite sprite;

public:
    Enemy(int h, int s, int d);
    virtual ~Enemy() {}

    // virtual voids
    virtual void takeDamage(int damage);
    virtual void setTexture(const sf::Texture& texture);
    virtual void detectPlayer(const Player& player);
    virtual void attack();
    virtual void die();
};

#endif  // ENEMY_H
