#include "Shooting.h";

Shooting::Shooting(float shootingDelay_c, float projectileSpeed_c)
    : shootingDelay(shootingDelay_c), projectileSpeed(projectileSpeed_c)
{

}

void Shooting::debugPrint() {
    std::cout << "Time Since Last Shot: " << timeSinceLastShot.asSeconds() << " seconds\n";
    std::cout << "Current Ammo: " << currentAmmo << "\n";
    std::cout << "Projectile Speed: " << projectileSpeed << "\n";
    std::cout << "Shooting Delay: " << shootingDelay << "\n";

    std::cout << "Number of Projectiles: " << projectiles.size() << "\n";
    for (size_t i = 0; i < projectiles.size(); ++i) {
        const auto& projectile = projectiles[i];
        const auto& position = projectile.first;
        const auto& direction = projectile.second;

        std::cout << "Projectile " << i + 1 << ": Position ("
            << position.x << ", " << position.y << "), "
            << "Direction (" << direction.x << ", " << direction.y << ")\n";
    }
}

void Shooting::setBulletTexture(const sf::Texture& texture) {
    sprite_s.setTexture(texture);
}

void Shooting::shoot(sf::Vector2f position, sf::Vector2f direction) {

    debugPrint();
    if (!sprite_s.getTexture()->getSize().x || !sprite_s.getTexture()->getSize().y) {
        log.infoLog("Bullet texture is not set!");
    }
    else
    {
        log.infoLog("Bullet texture is set!", 
            "\nSize x: ", sprite_s.getTexture()->getSize().x, 
            "\nSize y: ", sprite_s.getTexture()->getSize().y);
    }

    if (timeSinceLastShot.asSeconds() >= shootingDelay && currentAmmo > 0) {
        projectiles.push_back({ position, direction });
        timeSinceLastShot = sf::Time::Zero;
        --currentAmmo;
    }
}

void Shooting::update(sf::Time deltaTime) {
    timeSinceLastShot += deltaTime;
    infinityAmmo();
    // Update all projectiles
    for (auto& projectile : projectiles) {
        projectile.first += projectile.second * projectileSpeed * (deltaTime.asSeconds()*0.002f);
    }
}

// Function to draw projectiles in the game window
void Shooting::draw(sf::RenderWindow& window) {
    for (const auto& projectile : projectiles) {
        sprite_s.setPosition(projectile.first);
        window.draw(sprite_s);
    }
}

void Shooting::infinityAmmo()
{
    currentAmmo = INT16_MAX;
}

