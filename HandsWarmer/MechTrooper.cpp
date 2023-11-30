#include "MechTrooper.h"

// Constructor
MechTrooper::MechTrooper(int hp, int speed, int damage) : Enemy(hp, speed, damage) {
    // Initialization specific to MechTrooper, if any
}

// Override virtual functions, if necessary
void MechTrooper::attack() {
    // Specific attack logic for MechTrooper
}

