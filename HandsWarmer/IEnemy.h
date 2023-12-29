// IENEMY.H
#ifndef IENEMY_H
#define IENEMY_H

class IEnemy {
public:
    virtual void attack() = 0;
    virtual void takeDamage(int damage) = 0;
    virtual ~IEnemy() {}
};

#endif // IENEMY_H