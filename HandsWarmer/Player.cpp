#include "Player.h"

sf::Sprite Player::player_sprite;

Player::Player(float& speed_c, int& dmg_c, int& hp_c) : 
    speed(speed_c),
    dmg(dmg_c),
    hp(hp_c),
    isAlive(true),
    shouldMechTrooperBeAlive(true),
    gravity(980.f),
    isOnGround(true),
    leftJump(false),
    rightJump(false),
    velocity(sf::Vector2f(0.f, 0.f)),
    jumpVelocity(sf::Vector2f(0.f, -2500.f))
{

    player_sprite.setPosition(400.f, 400.f);

    // Set texture for bullet
    b1.setBulletTexture(bulletTexture);

    maxSpeed = 15.f;
    delayBetweenShots = 0.25f;

    // Magazine // Ammo
    mag.amountOfBulletsMagazineCanHold = 30;
    mag.currentAmountOfBullentsInMagazine = 30;
    mag.wholeAmmunitionForThatWeapon = 120;
}

void Player::setTexture(const sf::Texture& texture) {
    player_sprite.setTexture(texture);

    playerHitBox.x = texture.getSize().x;
    playerHitBox.y = texture.getSize().y;
}

void Player::handleInput() {
    velocity.x = 0.f;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        if (mag.currentAmountOfBullentsInMagazine == 0) {
            mag.reload();
        }
        else if ((timeSinceLastShot.asSeconds() >= delayBetweenShots) && (mag.currentAmountOfBullentsInMagazine > 0)) {
            b1.sprite_b.setPosition(playerCenter);
            // NTBLA :: For some reason it doesn't work without this line
            b1.sprite_b.setTextureRect(sf::IntRect(0, 0, 16, 22));

            b1.currVel_b = aimDirNorm * maxSpeed;

            bullets.push_back(Bullet(b1));

            timeSinceLastShot = sf::Time::Zero;

            --mag.currentAmountOfBullentsInMagazine;
            if (mag.wholeAmmunitionForThatWeapon != 0) 
                --mag.wholeAmmunitionForThatWeapon;

            log.infoLog("Bullets mag can hold: ", mag.amountOfBulletsMagazineCanHold);
            log.infoLog("Bullets in mag: ", mag.currentAmountOfBullentsInMagazine);
            log.infoLog("Whole ammunition: ", mag.wholeAmmunitionForThatWeapon);
        }
    }

    // Check which keys are pressed and update velocity
    if (isOnGround && sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
    {
        LeftJump();
    }
    if (isOnGround && sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
    {
        RightJump();
    }
    if (isOnGround && (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) 
    {
        StraightJump();
    }

    if (isOnGround && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x -= speed;
    }
    if (isOnGround && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x += speed;
    }
}

void Player::update(sf::Time deltaTime, const sf::Sprite& enemySprite_p, int enemyHp_p) {

    // Jumping
    if (leftJump && !isOnGround) {
        velocity.y += (gravity * 0.2f) * (deltaTime.asSeconds() * 30);
        velocity.x -= (speed) * (deltaTime.asSeconds() * 30);
    }
    else if (rightJump && !isOnGround)
    {
        velocity.y += (gravity * 0.2f) * (deltaTime.asSeconds() * 30);
        velocity.x += (speed) * (deltaTime.asSeconds() * 30);
    }
    else if (!isOnGround) {
        velocity.y += (gravity * 0.2f) * (deltaTime.asSeconds() * 30);
    }

    player_sprite.move(velocity * (deltaTime.asSeconds() * 0.5f));

    if (player_sprite.getPosition().y > 400.f) {
        player_sprite.setPosition(player_sprite.getPosition().x, 400.f);
        isOnGround = true;
        rightJump = false;
        leftJump = false;

        velocity.y = 0.f;
        velocity.x = 0.f;
    }

    // Borders for player to not leave window
    if (player_sprite.getPosition().x >= 800.f) {
        player_sprite.setPosition(720.f, player_sprite.getPosition().y);
    }
    if (player_sprite.getPosition().x <= 0.f) {
        player_sprite.setPosition(1.f, player_sprite.getPosition().y);
    }
    if (player_sprite.getPosition().y <= 0.f) {
        player_sprite.setPosition(player_sprite.getPosition().x, 1.f);
    }

    // Shooting
    timeSinceLastShot += deltaTime;

    countShootingTrijectory();

    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].sprite_b.move(bullets[i].currVel_b);

        if (bullets[i].sprite_b.getPosition().x < -20 || bullets[i].sprite_b.getPosition().x > 820 ||
            bullets[i].sprite_b.getPosition().y < -20 || bullets[i].sprite_b.getPosition().y > 620)
        {
            log.infoLog("Deleting bullet as it weint outside of the border...");
            bullets.erase(bullets.begin() + i);
        }
    }

    // Update player position
    playerCenter = player_sprite.getPosition();

    bulletCollision(enemySprite_p, playerHitBox, enemyHitBox, enemyHp_p);
}

void Player::render(sf::RenderWindow& window) {
    window.draw(player_sprite);
    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i].sprite_b);
    }
}

void Player::StraightJump() {
    // Apply jump velocity
    velocity.y += jumpVelocity.y;
    isOnGround = false;

    log.startLog(":: STRAIGHT JUMP ::");
}
void Player::LeftJump() {
    // Apply jump velocity
    velocity.y += jumpVelocity.y;
    velocity.x -= speed;
    isOnGround = false;
    leftJump = true;

    log.startLog(":: LEFT JUMP ::");
}
void Player::RightJump() {
    // Apply jump velocity
    velocity.y += jumpVelocity.y;
    velocity.x += speed;
    isOnGround = false;
    rightJump = true;

    log.startLog(":: RIGHT JUMP ::");
}

void Player::countShootingTrijectory()
{
    aimDir = mousePosWindow - playerCenter;
    length = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
    aimDirNorm = aimDir / length;
}

void Player::infinityAmmo()
{
    mag.wholeAmmunitionForThatWeapon = INT16_MAX;
}
void Player::setBulletTexture(const sf::Texture& texture)
{
    bulletTexture = texture;
}
void Player::setMousePos(const sf::Vector2f& mousePos)
{
    mousePosWindow = mousePos;
}

void Player::decreaceEnemyHp(int& hp, const int& dmg) {
    log.infoLog("Enemy Received DMG!");
    log.infoLog("HP Before subtraction: ", hp);

    hp = hp - dmg;

    log.infoLog("HP After subtraction: ", hp);

    if (hp <= 0) {
        enemyDied();
    }
}

void Player::enemyDied() {
    log.infoLog("Enemy died!");
    shouldMechTrooperBeAlive = false;
}

void Player::getEnemyTrooperHitBox(const sf::Vector2f& enemyHitbox_p) {
    enemyHitBox = enemyHitbox_p;
}

void Player::playerDied()
{
    isAlive = false;
    log.infoLog("Player has died!");
}

void Player::bulletCollision(const sf::Sprite& enemySprite_p, sf::Vector2f hitBoxPlayer, sf::Vector2f hitBoxEnemy, int enemyHp_p) {
    if (enemyHp == NULL) {
        enemyHp = enemyHp_p;
    }

    for (int i = bullets.size() - 1; i >= 0; i--) {
        if (bullets[i].sprite_b.getGlobalBounds().intersects(
            sf::FloatRect(enemySprite_p.getPosition().x, enemySprite_p.getPosition().y,
                hitBoxEnemy.x, hitBoxEnemy.y)))
        {
            decreaceEnemyHp(enemyHp, dmg);
            bullets.erase(bullets.begin() + i);
        }
    }
}