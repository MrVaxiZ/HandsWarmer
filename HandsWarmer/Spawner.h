#ifndef SPAWNER_H
#define SPAWNER_H

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Log.h"
#include "Enemy.h"

class Spawner {
private:
    std::vector<std::shared_ptr<Enemy>> enemies;
    sf::Clock spawnTimer;
    sf::Vector2f spawnPoint1;
    sf::Vector2f spawnPoint2;
    int maxEnemies;
    float spawnInterval;

public:
    Spawner(float interval, const sf::Vector2f& point1, const sf::Vector2f& point2, int max);

    template <typename T, typename... Args>
    void spawnEnemy(Args&&... args);

    void update(sf::Time deltaTime, const sf::Sprite& player, int& playerHp);
    void render(sf::RenderWindow& window);
};

#endif // ENEMYSPAWNER_H
