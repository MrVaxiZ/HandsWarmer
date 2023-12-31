#include "EnemyShooting.h"

EnemyShooting::EnemyShooting(Magazine& mag_c, Bullet& bullet_c, float delayBetweenShots_c, float maxSpeed_c, float length_c)
    : mag(mag_c), bullet(bullet_c), delayBetweenShots(delayBetweenShots_c), maxSpeed(maxSpeed_c), length(length_c)
{

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

void EnemyShooting::textureProvideCtor(const sf::Texture& texture) {

}

void EnemyShooting::texturesSwap(float time) {

}

void EnemyShooting::countShootingTrijectory() {
    aimDir = playerCenter;
    length = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
    aimDirNorm = aimDir / length;
}

void EnemyShooting::infinityAmmo() {
    mag.wholeAmmunitionForThatWeapon = INT16_MAX;
}

void EnemyShooting::bulletCollision() {

}