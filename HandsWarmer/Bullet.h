#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Bullet {
public:
    sf::Sprite sprite_b;
    sf::Vector2f currVel_b;
    float maxSpeed_b = 14.f;

    ///////////////
    // FUNCTIONS //
    ///////////////

    void setBulletTexture(const sf::Texture& txt);
};

#endif // BULLET_H
