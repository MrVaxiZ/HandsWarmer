#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include <thread>
#include <vector>
#include <future>

#include "TextureManager.h"
#include "MousePositionDisplay.h"
#include "Player.h"
#include "Level.h"
#include "MechTrooper.h"

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    TextureManager textureManager;
    Level level;
    Player player;
    MechTrooper mechTrooper;
    MousePositionDisplay mousePositionDisplay;

    void processEvents();
    void update(sf::Time deltaTime);
    void render();
};

#endif // GAME_H
