#include "Magazine.h"
//if (currentAmountOfBullentsInMagazine == 0) {
//}
void Magazine::reload()
{
    if (currentAmountOfBullentsInMagazine < amountOfBulletsMagazineCanHold) {
        int neededBullets = amountOfBulletsMagazineCanHold - currentAmountOfBullentsInMagazine;
        if (wholeAmmunitionForThatWeapon >= neededBullets) {
            wholeAmmunitionForThatWeapon -= neededBullets;
            currentAmountOfBullentsInMagazine = amountOfBulletsMagazineCanHold;

            std::cout << "Reloading!" << std::endl;
        }
        else if (wholeAmmunitionForThatWeapon > 0) {
            currentAmountOfBullentsInMagazine += wholeAmmunitionForThatWeapon;
            wholeAmmunitionForThatWeapon = 0;

            std::cout << "Reloading! not full clip" << std::endl;
        }
        else {
            // Play sound of empty clip
            std::cout << "NO AMMO" << std::endl;
        }
    }
}
