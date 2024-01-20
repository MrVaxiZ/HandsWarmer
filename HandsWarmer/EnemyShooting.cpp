#include "EnemyShooting.h"

EnemyShooting::EnemyShooting(Magazine& mag_c, Bullet& bullet_c, float delayBetweenShots_c, float bulletSpeed_c, int hp_c, int dmg_c)
    : mag(mag_c), bullet(bullet_c), delayBetweenShots(delayBetweenShots_c), bulletSpeed(bulletSpeed_c), hp(hp_c), dmg(dmg_c)
{
    // Debug
    mag.amountOfBulletsMagazineCanHold = INT16_MAX;
    mag.currentAmountOfBullentsInMagazine = INT16_MAX;
    mag.wholeAmmunitionForThatWeapon = INT16_MAX;
    // END Debug
}

bool EnemyShooting::playerDetect(const sf::Sprite& player, const sf::Sprite& enemy, float distance) {
    float playerPosition = player.getPosition().x;
    float mechPosition = enemy.getPosition().x;

    if (abs(playerPosition - mechPosition) <= distance) {
        return true;
    }
    else {
        return false;
    }
}

void EnemyShooting::countShootingTrijectory(const sf::Sprite& player, const sf::Sprite& enemy) {
    aimDir = player.getPosition() - enemy.getPosition();
    length = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
    aimDirNorm = aimDir / length;
}

void EnemyShooting::playerDecraseHp(const int& dmg, int& hp)
{
    log.infoLog("Player Received DMG!");
    log.infoLog("HP Before subtraction: ", hp);

    hp = hp - dmg;

    log.infoLog("HP After subtraction: ", hp);
    if (hp <= 0) {
        log.infoLog("Player died :<");
        playerDied();
    }
}

void EnemyShooting::playerDied()
{
    log.infoLog("Player died!");
}

void EnemyShooting::attack(const sf::Sprite& player, const sf::Sprite& enemy, float distance, bool reload, bool infinityAmmo)
{
    if (playerDetect(player, enemy, distance)) {
        if (reload) {
            if (mag.currentAmountOfBullentsInMagazine == 0) {
                mag.reload();
            }
        }
        
        if ((timeSinceLastShot.asSeconds() >= delayBetweenShots) && (mag.currentAmountOfBullentsInMagazine > 0)) {
            log.infoLog("Shooting!");
            bullet.sprite_b.setPosition(enemy.getPosition());
            // NTBLA :: For some reason it doesn't work without this line
            bullet.sprite_b.setTextureRect(sf::IntRect(0, 0, 16, 22));

            bullet.currVel_b = aimDirNorm * bulletSpeed;

            bullets.push_back(Bullet(bullet));

            timeSinceLastShot = sf::Time::Zero;

            if (infinityAmmo) {
                --mag.currentAmountOfBullentsInMagazine;
                if (mag.wholeAmmunitionForThatWeapon != 0)
                    --mag.wholeAmmunitionForThatWeapon;
            }

            log.infoLog("Bullets mag can hold: ", mag.amountOfBulletsMagazineCanHold);
            log.infoLog("Bullets mag can hold: ", mag.currentAmountOfBullentsInMagazine);
            log.infoLog("Whole ammunition: ", mag.wholeAmmunitionForThatWeapon);
        }
    }
}

void EnemyShooting::bulletCollision(sf::Vector2f hitBoxPlayer, sf::Vector2f hitBoxEnemy, int& playerHp) {

    for (int i = bullets.size() - 1; i >= 0; i--) {
        if (bullets[i].sprite_b.getGlobalBounds().intersects(
            sf::FloatRect(player_sprite.getPosition().x, player_sprite.getPosition().y,
                hitBoxPlayer.x, hitBoxPlayer.y))) 
        {
            playerDecraseHp(dmg, playerHp);
            bullets.erase(bullets.begin() + i);
        }
    }
}

void EnemyShooting::bulletsUpdate(sf::Time deltaTime, const sf::Sprite& player, const sf::Sprite& enemy) {
    timeSinceLastShot += deltaTime;
    player_sprite = player;

    // Count shooting trijectory for enemy bullets
    countShootingTrijectory(player, enemy);

    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].sprite_b.move(bullets[i].currVel_b);

        if (bullets[i].sprite_b.getPosition().x < -20 || bullets[i].sprite_b.getPosition().x > 820 ||
            bullets[i].sprite_b.getPosition().y < -20 || bullets[i].sprite_b.getPosition().y > 620)
        {
            bullets.erase(bullets.begin() + i);
        }
    }

    // Update player position
    playerCenter = player.getPosition();
}

void EnemyShooting::bulletsRender(sf::RenderWindow& window) {
    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i].sprite_b);
    }
}