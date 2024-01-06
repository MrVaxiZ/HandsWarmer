#include "MechTrooper.h"

// Constructor
MechTrooper::MechTrooper(float speed_c, int dmg_c, int hp_c)
    : speed(speed_c), dmg(dmg_c), hp(hp_c), Enemy(100, 0, 5),
    enemyShooting(magazine, bullet, 0.15f, 10.0f, hp_c, dmg_c),
    movement(sprite)
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
    movement.debug();
}

void MechTrooper::update(sf::Time deltaTime, const sf::Sprite& player, int& playerHp) {
    attack(player);
    enemyShooting.bulletsUpdate(deltaTime, player, sprite);
    enemyShooting.bulletCollision(playerHitbox, enemyHitbox, playerHp);
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

void MechTrooper::getPropertiesOneTime()
{
}

void MechTrooper::getPropertiesConstantly(const sf::Vector2f Player_HitBox) 
{
    playerHitbox = Player_HitBox;
}