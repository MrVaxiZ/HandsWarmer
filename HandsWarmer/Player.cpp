#include "Player.h"
#include "Log.h"

sf::Sprite Player::sprite;

Player::Player() : speed(1000.f), gravity(980.f), isOnGround(true), leftJump(false), rightJump(false), hp(100),
velocity(sf::Vector2f(0.f, 0.f)), jumpVelocity(sf::Vector2f(0.f, -2500.f)) 
{
    sprite.setPosition(400.f, 400.f);
}

void Player::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);
}

void Player::handleInput() {
    // Reset velocity
    velocity.x = 0.f;

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
    // Apply gravity if the player is not on the ground

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

    sprite.move(velocity * (deltaTime.asSeconds() * 0.5f));

    if (sprite.getPosition().y > 400.f) {
        sprite.setPosition(sprite.getPosition().x, 400.f);
        isOnGround = true;
        rightJump = false;
        leftJump = false;

        velocity.y = 0.f;
        velocity.x = 0.f;
    }

    // Borders for player to not leave window
    if (sprite.getPosition().x >= 800.f) {
        sprite.setPosition(720.f, sprite.getPosition().y);
    }
    if (sprite.getPosition().x <= 0.f) {
        sprite.setPosition(1.f, sprite.getPosition().y);
    }
    if (sprite.getPosition().y <= 0.f) {
        sprite.setPosition(sprite.getPosition().x, 1.f);
    }
}

void Player::StraightJump() {
    // Apply jump velocity
    velocity.y += jumpVelocity.y;
    isOnGround = false;
    Log log;

    log.startLog(":: STRAIGHT JUMP ::");
    log.infoLog("Velocity.y: ", velocity.y, '\n');
    log.infoLog("JumpVelocity.y: ", jumpVelocity.y, '\n');
}
void Player::LeftJump() {
    // Apply jump velocity
    velocity.y += jumpVelocity.y;
    velocity.x -= speed;
    isOnGround = false;
    leftJump = true;
    Log log;

    log.startLog(":: LEFT JUMP ::");
    log.infoLog("Velocity.y: ", velocity.y, '\n');
    log.infoLog("JumpVelocity.y: ", jumpVelocity.y, '\n');
    log.infoLog("Velocity.x: ", velocity.x, '\n');
    log.infoLog("Speed: : ", speed, '\n');
}
void Player::RightJump() {
    // Apply jump velocity
    velocity.y += jumpVelocity.y;
    velocity.x += speed;
    isOnGround = false;
    rightJump = true;
    Log log;

    log.startLog(":: RIGHT JUMP ::");
    log.infoLog("Velocity.y: ", velocity.y, '\n');
    log.infoLog("JumpVelocity.y: ", jumpVelocity.y, '\n');
    log.infoLog("Velocity.x: ", velocity.x, '\n');
    log.infoLog("Speed: : ", speed, '\n');
}

void Player::render(sf::RenderWindow& window) {
    // Draw the player's sprite
    window.draw(sprite);
}