#ifndef MECHTROOPER_H
#define MECHTROOPER_H

#include "Enemy.h"
#include "EnemyShooting.h"
#include "Movement.h"
#include "Log.h"

class MechTrooper : public Enemy {
private:
    Log log;
    Bullet bullet;
    Magazine magazine;
    EnemyShooting enemyShooting;
    Movement movement;
    sf::Sprite sprite;
    sf::Vector2f hitBox;
    float distance_p;

    float speed;
    int dmg;
    int hp;

    // HitBox TODO::Make it more advance to reflect actual shape of texture and to make head
    //               as separete hitbox in order to multiply dmg once it's been hit.
    sf::Vector2f enemyHitbox;
    sf::Vector2f playerHitbox;

public:
    sf::Texture bulletTexture;

    MechTrooper(float speed_c, int dmg_c, int hp_c);

    // Override methods
    void attack(const sf::Sprite& player) override;
    void update(sf::Time deltaTime, const sf::Sprite& player, int& playerHp);
    void render(sf::RenderWindow& window);
    void setTexture(const sf::Texture& texture);
    void getPlayerHitBox(const sf::Vector2f Player_HitBox);
    void getPropertiesOneTime();
    void getPropertiesConstantly(const sf::Vector2f Player_HitBox);
};

#endif  // MECHTROOPER_H
