#include "Shooting.h";

sf::Sprite Shooting::sprite_s;

Shooting::Shooting(float shootingDelay_c, float projectileSpeed_c)
    : shootingDelay(shootingDelay_c), projectileSpeed(projectileSpeed_c)
{

}

void Shooting::setBulletTexture(sf::Texture texture) {
    sprite_s.setTexture(texture);
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
        sprite_s.setPosition(projectile.first);
        window.draw(sprite_s);
    }
}

