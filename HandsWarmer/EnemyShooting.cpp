#include "EnemyShooting.h"

EnemyShooting::EnemyShooting(Magazine& mag_c, Bullet& bullet_c, float delayBetweenShots_c, float maxSpeed_c, float length_c, int hp_c, int dmg_c)
    : mag(mag_c), bullet(bullet_c), delayBetweenShots(delayBetweenShots_c), maxSpeed(maxSpeed_c), length(length_c), hp(hp_c), dmg(dmg_c)
{
    // Debug
    mag.amountOfBulletsMagazineCanHold = INT16_MAX;
    mag.currentAmountOfBullentsInMagazine = INT16_MAX;
    mag.wholeAmmunitionForThatWeapon = INT16_MAX;
    // END Debug
}

bool EnemyShooting::detectPlayer(const sf::Sprite& player, const sf::Sprite& enemy, float distance) {
    float playerPosition = player.getPosition().x;
    float mechPosition = enemy.getPosition().x;

    if (abs(playerPosition - mechPosition) <= distance) {
        log.infoLog("Shooting!");
        return true;
    }
    else {
        return false;
    }
}

void EnemyShooting::countShootingTrijectory(const sf::Sprite& player) {
    aimDir = player.getPosition();
    length = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
    aimDirNorm = aimDir / length;
}

void EnemyShooting::decraseHp(const int& dmg, int& hp)
{
    hp =- dmg;
    if (dmg <= 0) {
        die();
    }
}

void EnemyShooting::die()
{
    log.infoLog("Enemy died!");
}

void EnemyShooting::attack(const sf::Sprite& player, const sf::Sprite& enemy, float distance, bool reload, bool infinityAmmo)
{
    if (detectPlayer(player, enemy, distance)) {
        if (reload) {
            if (mag.currentAmountOfBullentsInMagazine == 0) {
                mag.reload();
            }
        }
        
        if ((timeSinceLastShot.asSeconds() >= delayBetweenShots) && (mag.currentAmountOfBullentsInMagazine > 0)) {
            bullet.sprite_b.setPosition(playerCenter);
            // NTBLA :: For some reason it doesn't work without this line
            bullet.sprite_b.setTextureRect(sf::IntRect(0, 0, 16, 22));

            bullet.currVel_b = aimDirNorm * maxSpeed;

            bullets.push_back(Bullet(bullet));

            timeSinceLastShot = sf::Time::Zero;

            if (infinityAmmo) {
                --mag.currentAmountOfBullentsInMagazine;
                if (mag.wholeAmmunitionForThatWeapon != 0)
                    --mag.wholeAmmunitionForThatWeapon;
            }

            std::cout << "Bullets mag can hold: " << mag.amountOfBulletsMagazineCanHold << std::endl;
            std::cout << "Bullets in mag: " << mag.currentAmountOfBullentsInMagazine << std::endl;
            std::cout << "Whole ammunition: " << mag.wholeAmmunitionForThatWeapon << std::endl;
        }
    }
}

void EnemyShooting::bulletCollision(sf::Vector2f hitBoxPlayer, sf::Vector2f hitBoxEnemy) {

    for (int i = bullets.size() - 1; i >= 0; i--) {
        if (bullets[i].sprite_b.getGlobalBounds().intersects(
            sf::FloatRect(player_sprite.getPosition().x, player_sprite.getPosition().y,
                hitBoxPlayer.x, hitBoxPlayer.y))) 
        {
            decraseHp(dmg, hp);
            bullets.erase(bullets.begin() + i);
        }
    }
}


void EnemyShooting::bulletsUpdate(sf::Time deltaTime, const sf::Sprite& player) {
    timeSinceLastShot += deltaTime;
    player_sprite = player;

    // Count shooting trijectory for enemy bullets
    countShootingTrijectory(player);

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
