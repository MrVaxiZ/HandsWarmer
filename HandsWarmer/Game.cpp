#include "Game.h"
#include "Log.h"

Game::Game() : 
    window(sf::VideoMode(800, 600), "Hands Warmer"),
    player(),
    mechTrooper(0, 0, 0),
    mousePositionDisplay(window) 
    {

    window.setFramerateLimit(360);
    Log log;

    std::vector<std::pair<std::string, std::string>> texturesToLoad = {
        {"playerTexture", "Textures\\character.png"},
        {"mechTrooper", "Textures\\mechTrooper-PointLeft_ProperSize.png"},
        {"shootMechTrooper", "Textures\\buller_txt_OB_r.png"},
    };

    // Load textures asynchronously
    std::vector<std::future<bool>> futures;
    for (const auto& textureInfo : texturesToLoad) {
        futures.push_back(std::async(std::launch::async, [this, &log, &textureInfo]() {
            if (!textureManager.loadTexture(textureInfo.first, textureInfo.second)) {
                log.errorLog("Could not load texture: " + textureInfo.first);
                return false;
            }
        log.infoLog(textureInfo.first + " texture loaded! OK");
        return true;
            }));
    }

    // Wait for all textures to load
    for (auto& future : futures) {
        future.wait();
    }

    // Now that all textures are loaded, set them to the objects
    try
    {
        player.setTexture(textureManager.getTexture("playerTexture"));
        mechTrooper.setTexture(textureManager.getTexture("mechTrooper"));
        mechTrooper.provideTexture(textureManager.getTexture("shootMechTrooper"));
    }
    catch (const std::exception& e)
    {
        log.errorLog("Error during assigning texture to object (Probably key has not been found)",
            "\nError: ", e.what());
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
    mechTrooper.update(deltaTime);
    mousePositionDisplay.update();
}

void Game::render() {
    window.clear();
    level.render(window);
    player.render(window);
    mechTrooper.render(window);
    mousePositionDisplay.render(window);
    window.display();
}

