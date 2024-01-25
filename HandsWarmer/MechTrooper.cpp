#include "MechTrooper.h"

// Constructor
MechTrooper::MechTrooper(float& speed_c, int& dmg_c, int& hp_c)
    : speed(speed_c), dmg(dmg_c), hp(hp_c), Enemy(100, 0, 5),
    enemyShooting(magazine, bullet, 0.15f, 10.0f, hp_c, dmg_c),
    movement(sprite, distance_p)
{
    isAlive = true;

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

void MechTrooper::update(sf::Time deltaTime, const sf::Sprite& player, int& playerHp, const bool& shouldMechTrooperBeAlive_p) {
    if (!shouldMechTrooperBeAlive_p) { isAlive = false; }

    if (isAlive) { // TBR:: Made in order to save memory
        sf::Vector2f direction = player.getPosition() - sprite.getPosition();
        float distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

        if (distance > distance_p) {
            movement.followPlayer(player, deltaTime);
        }
        else {
            movement.maintainDistance(player, deltaTime);
        }

        attack(player);
        enemyShooting.bulletsUpdate(deltaTime, player, sprite);
        enemyShooting.bulletCollision(playerHitbox, enemyHitbox, playerHp);
    }
}

void MechTrooper::render(sf::RenderWindow& window) {
    if(isAlive){
        window.draw(sprite);
        enemyShooting.bulletsRender(window);
    }
    else
    {
        //MechTrooper::~MechTrooper(); <- 
        // this should be done this way but currently it's not becasue it breaks the app
        // MV:: The issue is with texture manager it keeps trying to load txt after object gets deleted
        //  probably will have to remake this thing.
    }
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

sf::Vector2f MechTrooper::returnEnemyHitBox() {
    return enemyHitbox;
}