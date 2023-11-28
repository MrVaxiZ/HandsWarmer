#include <iostream>
#include <SFML/Graphics.hpp>

class Weapon {
protected:
    int damage;
    float range;
    std::string name;
    static sf::Sprite sprite;

public:
    Weapon(int dmg, float rng, std::string nm) : damage(dmg), range(rng), name(nm) {}

    void setTexture(const sf::Texture& texture) {
        sprite.setTexture(texture);
    }

    virtual void shoot() {
        // Shooting logic...
    }

    virtual void upgrade() {
        // Upgrades logic...
    }

    virtual void display() {
        // Texture ...
    }
};
