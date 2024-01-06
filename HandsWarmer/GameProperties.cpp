#include "GameProperties.h"

sf::Vector2f GameProperties::windowBorders;
float GameProperties::floorPos;

void GameProperties::setWindowBorder(const float& windowWidth, const float& windowHeight) {
    windowBorders.x = windowWidth;
    windowBorders.y = windowHeight;
}

void GameProperties::setFloorPos(const float& floorPos_p) {
    floorPos = floorPos_p;
}
