#include <SFML/Graphics.hpp>
#include <vector>

class Shooting {
public:
    Shooting(float shootingDelay, const sf::Texture& texture, sf::Sprite userS)
        : shootingDelay(shootingDelay), texture_v(texture), user(userS), timeSinceLastShot(sf::Time::Zero) {}

    void setShootingDelay(float delay) {
        shootingDelay = delay;
    }

    void setTexture(const sf::Texture& texture) {
        texture_v = texture;
    }

    void shoot(sf::Vector2f position, sf::Vector2f direction) {
        if (timeSinceLastShot.asSeconds() >= shootingDelay && currentAmmo > 0) {
            // Add a new projectile
            projectiles.push_back({ position, direction });
            timeSinceLastShot = sf::Time::Zero;
            --currentAmmo;  // Decrease ammo
        }
    }

    void update(sf::Time deltaTime) {
        timeSinceLastShot += deltaTime;

        // Update all projectiles
        for (auto& projectile : projectiles) {
            projectile.first += projectile.second * projectileSpeed * deltaTime.asSeconds();
            // You can add collision checks and other updates here
        }

    }

    // Function to draw projectiles in the game window
    void draw(sf::RenderWindow& window) {
        for (const auto& projectile : projectiles) {
            sf::Sprite sprite;
            sprite.setTexture(texture_v);
            sprite.setPosition(projectile.first);
            window.draw(sprite);
        }
    }

private:
    float shootingDelay;
    sf::Texture texture_v;
    sf::Sprite user;
    sf::Time timeSinceLastShot;
    int currentAmmo = INT16_MAX;  // Example ammo count
    float projectileSpeed = 300.0f;  // Speed of the projectile
    std::vector<std::pair<sf::Vector2f, sf::Vector2f>> projectiles; // Pair of position and direction
};
