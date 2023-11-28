#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Player.h"
#include "Level.h"
#include "MousePositionDisplay.h"
#include "Enemy.h"

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    TextureManager textureManager;
    Level level;
    Player player;
    Enemy enemy;
    MousePositionDisplay mousePositionDisplay;

    void processEvents();
    void update(sf::Time deltaTime);
    void render();
};

#endif // GAME_H
