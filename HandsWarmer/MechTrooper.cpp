#include "MechTrooper.h"

// Constructor
MechTrooper::MechTrooper(int hp, int speed, int damage)
    : Enemy(hp, speed, damage),
    enemyShooting(magazine, bullet, 0.15f, 10.0f, hp, damage)
{
    name = "MechTrooper";
    distance_p = 200.f;
    sprite.setPosition(100.f, 400.f);

    bullet.setBulletTexture(bulletTexture);

    magazine.currentAmountOfBullentsInMagazine = INT16_MAX;
    magazine.amountOfBulletsMagazineCanHold = 10;
    magazine.wholeAmmunitionForThatWeapon = 30;
}

void MechTrooper::attack(const sf::Sprite& player) {
    enemyShooting.attack(player, sprite, distance_p, false, true);
}

void MechTrooper::update(sf::Time deltaTime, const sf::Sprite& player) {
    Enemy::update(deltaTime);
    attack(player);
    enemyShooting.bulletsUpdate(deltaTime, player, sprite);
    enemyShooting.bulletCollision(playerHitbox, enemyHitbox);
}

void MechTrooper::render(sf::RenderWindow& window) {
    window.draw(sprite);
    enemyShooting.bulletsRender(window);
}

void MechTrooper::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);

    enemyHitbox.x = texture.getSize().x;
    enemyHitbox.y = texture.getSize().y;
}

void MechTrooper::getPlayerHitBox(const sf::Vector2f Player_HitBox)
{
    playerHitbox = Player_HitBox;
}
