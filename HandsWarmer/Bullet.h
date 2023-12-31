#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Bullet {
public:
    sf::CircleShape shape_b;
    //sf::Texture txt;
    sf::Vector2f currVel_b;
    float maxSpeed_b;
};

#endif // BULLET_H
