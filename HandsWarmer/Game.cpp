#include "Game.h"
#include "Log.cpp"


Game::Game() : window(sf::VideoMode(800, 600), "Hands Warmer"), player(), mousePositionDisplay(window){
    window.setFramerateLimit(360);
    Log log;

    std::vector<std::pair<std::string, std::string>> texturesToLoad = {
        {"playerTexture", "C:\\Users\\vaxiz\\source\\repos\\HandsWarmer\\HandsWarmer\\Textures\\character.png"},
        {"mechTrooper", "C:\\Users\\vaxiz\\source\\repos\\HandsWarmer\\HandsWarmer\\Textures\\mechTrooper.png"},
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
        }
    }

    if (!level.load("C:\\Users\\vaxiz\\source\\repos\\HandsWarmer\\HandsWarmer\\Textures\\background.jpg")) {
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

