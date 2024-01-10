#ifndef GAMEPROPERTIES_H
#define GAMEPROPERTIES_H

#include <SFML/Graphics.hpp>

class GameProperties {
public:
    static sf::Vector2f windowBorders;
    static float floorPos;

    ///////////////
    // FUNCTIONS //
    ///////////////

    void setWindowBorder(const float& windowWidth_p, const float& windowHeight_p);
    void setFloorPos(const float& floorPos_p);
};

#endif // GAMEPROPERTIES_H
