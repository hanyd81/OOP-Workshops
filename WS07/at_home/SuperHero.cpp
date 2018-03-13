// SuperHero.h
//name Yadong Han
// ID 151799160
//Email yhan61@myseneca.ca


#include <iostream>
#include "SuperHero.h"

using namespace std;

namespace sict {

	SuperHero::SuperHero()
	{
		m_bonus = -1;
		m_defence = -1;
	}

	SuperHero::SuperHero(const char* name, int health, int attack, int bonus, int defence) : Hero(name, health, attack)
	{
		if (bonus < 0 || defence < 0) {
			*this = SuperHero();
		}
		else
		{
			m_bonus = bonus;
			m_defence = defence;
		}

	}

	int SuperHero::attackStrength() const
	{
		if (isEmpty())
			return 0;
		else
			return m_bonus + Hero::attackStrength();
	}

	int SuperHero::defend() const
	{
		if (isEmpty())
			return 0;
		else
			return m_defence;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{
		int round = 0;
		bool keepOn = true;
		SuperHero a = first;
		SuperHero b = second;

		while (keepOn && round < max_rounds) {
			b -= a.attackStrength()-b.defend();
			a -= b.attackStrength()-a.defend();
			round++;
			if (!a.isAlive() || !b.isAlive())
				keepOn = false;

		}

		cout << "Super Fight! " << first << " vs " << second <<
			": Winner is ";

		if (b.isAlive() && !a.isAlive()) {
			cout << second << " in " << round << " rounds." << endl;
			return second;

		}
		else {
			cout << first << " in " << round << " rounds." << endl;
			return first;
		}
	}

}