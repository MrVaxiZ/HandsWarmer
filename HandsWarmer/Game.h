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
#include "GameProperties.h"

class Game {
public:
    const int windowHeight = 600;
    const int windowWidth = 800;
    sf::RenderWindow window;
    sf::Vector2f mousePosWindow;
    GameProperties gameProperties;
    TextureManager textureManager;
    Level level;
    Player player;
    MechTrooper mechTrooper;
    MousePositionDisplay mousePositionDisplay;

    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
};

#endif // GAME_H
