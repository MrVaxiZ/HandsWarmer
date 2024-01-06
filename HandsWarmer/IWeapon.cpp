#include <iostream>
#include <SFML/Graphics.hpp>

class IWeapon {
protected:
    int damage;
    float range;
    std::string name;
    static sf::Sprite sprite;

public:
    IWeapon(int dmg, float rng, std::string nm) : damage(dmg), range(rng), name(nm) {}

    void setTexture(const sf::Texture& texture) {
        sprite.setTexture(texture);
    }

    virtual void upgrade() {
        // Upgrades logic...
    }

    virtual void display() {
        // Texture ...
    }
};
