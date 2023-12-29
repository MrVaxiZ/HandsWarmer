#include "Player.h"

sf::Sprite Player::player_sprite;

Player::Player() : speed(1000.f), gravity(980.f), isOnGround(true), leftJump(false), rightJump(false), hp(100),
velocity(sf::Vector2f(0.f, 0.f)), jumpVelocity(sf::Vector2f(0.f, -2500.f)) 
{
    this->shape.setRadius(5.f);
    this->shape.setFillColor(sf::Color::Red);

    player_sprite.setPosition(400.f, 400.f);

    maxSpeed = 15.f;
}

void Player::setTexture(const sf::Texture& texture) {
    player_sprite.setTexture(texture);
}

void Player::handleInput() {
    velocity.x = 0.f;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        b1.shape_b = shape;
        b1.shape_b.setPosition(playerCenter);
        b1.currVel_b = aimDirNorm * maxSpeed;

        bullets.push_back(Bullet(b1));
    }

    // Check which keys are pressed and update velocity
    if (isOnGround && sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
    {
        LeftJump();
    }
    if (isOnGround && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
    {
        RightJump();
    }
    if (isOnGround && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) 
    {
        StraightJump();
    }

    if (isOnGround && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x -= speed;
    }
    if (isOnGround && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x += speed;
    }
}

void Player::update(sf::Time deltaTime) {

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
        velocity.y += (gravity*0.2f) * (deltaTime.asSeconds() * 30);
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
    countShootingTrijectory();

    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].shape_b.move(bullets[i].currVel_b);

        if (bullets[i].shape_b.getPosition().x < 0 || bullets[i].shape_b.getPosition().x > 800 ||
            bullets[i].shape_b.getPosition().y < 0 || bullets[i].shape_b.getPosition().y > 600) 
        {
            bullets.erase(bullets.begin() + i);
        }
    }

    // Update player position
    playerCenter = player_sprite.getPosition();
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

void Player::setMousePos(const sf::Vector2f& mousePos)
{
    mousePosWindow = mousePos;
}

void Player::countShootingTrijectory()
{
    aimDir = mousePosWindow - playerCenter;
    length = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
    aimDirNorm = aimDir / length;
}

void Player::render(sf::RenderWindow& window) {
    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i].shape_b);
    }

    window.draw(player_sprite);
}