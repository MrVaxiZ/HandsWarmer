#include <iostream>

#include "Player.cpp"

#include "Enemy.h"

#include <SFML/Graphics.hpp>

class Enemy {
protected:
    int hp;
    int speed;
    int damage;
    std::string name;
    static sf::Sprite sprite;

public:
    Enemy(int h, int s, int a) : hp(h), speed(s), damage(a) {}

    void setTexture(const sf::Texture& texture) {
        sprite.setTexture(texture);
    }

    virtual void detectPlayer(const Player& player) {
        // Player detection logic ...
    }

    virtual void attack() {
        // Attack logic...
    }

    virtual void die() {
        // Dying logic...
    }

    void takeDamage(int damage) {
        hp -= damage;
        if (hp <= 0) {
            die();
        }
    }
};
