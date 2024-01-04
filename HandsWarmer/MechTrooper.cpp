#include "MechTrooper.h"

// Constructor
MechTrooper::MechTrooper(int hp, int speed, int damage)
    : Enemy(hp, speed, damage),
    enemyShooting(magazine, bullet, 1.0f, 10.0f, 100.0f, hp, damage)
{
    name = "MechTrooper";
    sprite.setPosition(100.f, 400.f);

    bullet.setBulletTexture(bulletTexture);

    magazine.currentAmountOfBullentsInMagazine = 10;
    magazine.amountOfBulletsMagazineCanHold = 10;
    magazine.wholeAmmunitionForThatWeapon = 30;
}

void MechTrooper::attack(const sf::Sprite& player) {
    enemyShooting.attack(player, sprite, distance_p, false, true);
}

void MechTrooper::update(sf::Time deltaTime, const sf::Sprite& player) {
    Enemy::update(deltaTime);
    enemyShooting.bulletsUpdate(deltaTime, player);
    attack(player);

    //enemyShooting.bulletCollision(playerBullets, enemyShooting.bullets, playerHitBox, enemyShooting.enemyHitbox);
}

void MechTrooper::render(sf::RenderWindow& window) {
    window.draw(sprite);
    enemyShooting.bulletsRender(window);
}

void MechTrooper::setTexture(const sf::Texture& texture) {


    sprite.setTexture(texture);
}
