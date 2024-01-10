#include "MechTrooper.h"

// Constructor
MechTrooper::MechTrooper(float speed_c, int dmg_c, int hp_c)
    : speed(speed_c), dmg(dmg_c), hp(hp_c), Enemy(100, 0, 5),
    enemyShooting(magazine, bullet, enemyHitbox, 0.15f, 10.0f, playerDmg, hp_c, dmg_c),
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
}

void MechTrooper::update(sf::Time deltaTime, const sf::Sprite& player, int& playerHp) {
    attack(player);
    enemyShooting.bulletsUpdate(deltaTime, player, sprite);
    enemyShooting.bulletCollision(playerHitbox, playerHp, hp);
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

void MechTrooper::getPropertiesOneTime(const int& playerDmg_p) // Think of a way to get dmg by reference
{
	playerDmg = playerDmg_p;
}

void MechTrooper::getPropertiesConstantly(const sf::Vector2f Player_HitBox) 
{
    playerHitbox = Player_HitBox;
}