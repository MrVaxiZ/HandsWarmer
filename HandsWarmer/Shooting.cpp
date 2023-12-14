#include "Shooting.h";

Shooting::Shooting(float shootingDelay_c, float projectileSpeed_c, const sf::Texture& texture_c, const sf::Sprite& user_c)
    : shootingDelay(shootingDelay_c), projectileSpeed(projectileSpeed_c), texture(texture_c), user(user_c)
{

}

void Shooting::setShootingDelay(float delay) {
    shootingDelay = delay;
}

void Shooting::shoot(sf::Vector2f position, sf::Vector2f direction) {
    if (timeSinceLastShot.asSeconds() >= shootingDelay && currentAmmo > 0) {
        // Add a new projectile
        projectiles.push_back({ position, direction });
        timeSinceLastShot = sf::Time::Zero;
        --currentAmmo;
    }
}

void Shooting::update(sf::Time deltaTime) {
    timeSinceLastShot += deltaTime;

    // Update all projectiles
    for (auto& projectile : projectiles) {
        projectile.first += projectile.second * projectileSpeed * deltaTime.asSeconds();
    }
}

// Function to draw projectiles in the game window
void Shooting::draw(sf::RenderWindow& window) {
    for (const auto& projectile : projectiles) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(projectile.first);
        window.draw(sprite);
    }
}

