// SuperHero.h
//name Yadong Han
// ID 151799160
//Email yhan61@myseneca.ca

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {

		int m_bonus;
		int m_defence;

	public:
		SuperHero();
		SuperHero(const char* name, int health, int attack, int bonus, int defence);
		int attackStrength() const;
		int defend() const;

};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);



}


#endif // !SICT_SUPERHERO_H


