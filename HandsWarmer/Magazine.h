// Magazine.h
#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Log.h"

class Magazine {
public:
	Log log;

	int currentAmountOfBullentsInMagazine;
	int amountOfBulletsMagazineCanHold;
	int wholeAmmunitionForThatWeapon;
	//int ID; // ID of a weapon for future use;

	///////////////
	// FUNCTIONS //
	///////////////

	void reload();
};

#endif  // Magazine.h
