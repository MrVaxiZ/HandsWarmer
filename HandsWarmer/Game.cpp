#include "Game.h"

#include "Log.h"

Game::Game() : window(sf::VideoMode(800, 600), "Hands Warmer"), player(), mechTrooper(100, 1000, 0),
mousePositionDisplay(window){
    window.setFramerateLimit(360);
    Log log;

    std::vector<std::pair<std::string, std::string>> texturesToLoad = {
        {"playerTexture", "Textures\\character.png"},
        {"mechTrooper", "Textures\\mechTrooper-PointLeft_ProperSize.png"},
    };

    for (const auto& textureInfo : texturesToLoad) {
        if (!textureManager.loadTexture(textureInfo.first, textureInfo.second)) {
            log.errorLog("Could not load texture: " + textureInfo.first);
        }
        else {
            log.infoLog(textureInfo.first + " texture loaded! OK");
            if (textureInfo.first == "playerTexture") {
                player.setTexture(textureManager.getTexture(textureInfo.first));
            }
            log.infoLog(textureInfo.first + " texture loaded! OK");
            if (textureInfo.first == "mechTrooper") {
                mechTrooper.setTexture(textureManager.getTexture(textureInfo.first));
            }
        }
    }

    if (!level.load("Textures\\background.jpg")) {
        log.errorLog("Could not load level background!");
    }
    else {
        log.infoLog("Background texture loaded! OK");
    }
}

void Game::run() {
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        timeSinceLastUpdate += deltaTime;

        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    player.handleInput();
}

void Game::update(sf::Time deltaTime) {
    player.update(deltaTime);
    mousePositionDisplay.update();
}

void Game::render() {
    window.clear();
    level.render(window);
    player.render(window);
    mousePositionDisplay.render(window);
    window.display();
}

