#include "Spawner.h"

Spawner::Spawner(float interval, const sf::Vector2f& point1, const sf::Vector2f& point2, int max)
    : spawnInterval(interval), spawnPoint1(point1), spawnPoint2(point2), maxEnemies(max) {
}

template <typename T, typename... Args>
void Spawner::spawnEnemy(Args&&... args) {
    if (enemies.size() >= maxEnemies || spawnTimer.getElapsedTime().asSeconds() < spawnInterval) {
        return;
    }

    auto enemy = std::make_shared<T>(std::forward<Args>(args)...);
    enemy->setPosition((rand() % 2 == 0) ? spawnPoint1 : spawnPoint2);
    enemies.push_back(enemy);

    spawnTimer.restart();
}

void Spawner::update(sf::Time deltaTime, const sf::Sprite& player, int& playerHp) {
    for (auto& enemy : enemies) {
        //enemy->update(deltaTime, player, playerHp);
    }
}

void Spawner::render(sf::RenderWindow& window) {
    for (auto& enemy : enemies) {
        enemy->render(window);
    }
}
