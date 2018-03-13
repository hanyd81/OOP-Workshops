// Hero.h
//name Yadong Han
// ID 151799160
//Email yhan61@myseneca.ca

#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace sict {
	Hero::Hero()
	{
		m_name[0] = '\0';
		m_health = -1;
		m_attact = -1;
	}

	Hero::Hero(char* name, int health, int attack)
	{
		if (name != nullptr&&name[0] != '\0'&& health > 0 && attack >= 0) {
			strncpy(m_name, name, 40);
			m_name[40] = '\0';
			m_health = health;
			m_attact = attack;
		}
		else
			*this = Hero();
	}

	void Hero::operator-=(int attack)
	{
		if (attack > 0) {
			m_health -= attack;
		}
		if (m_health < 0)
			m_health = 0;
	}

	bool Hero::isAlive() const
	{
		return m_health > 0;
	}

	int Hero::attackStrength() const
	{
		return m_attact;
	}

	ostream& operator<<(ostream& os, const Hero& hero)
	{
		if (hero.m_name[0]=='\0') {
			os << "No hero";
		}
		else
			os << hero.m_name;
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second)
	{
		int round = 0;
		bool keepOn = true;
		Hero a = first;
		Hero b = second;
			
		while (keepOn && round < max_rounds) {
			b -= a.attackStrength();
			a -= b.attackStrength();
			round++;
			if (!a.isAlive() || !b.isAlive())
				keepOn = false;
			
		}
		
		cout  << "Ancient Battle! " << first << " vs " << second <<
			": Winner is ";

		if (b.isAlive() && !a.isAlive()) {
			cout << second << " in " << round << " rounds."<<endl;
			return second;

		}	
		else {
			cout << first << " in " << round << " rounds."<<endl;
			return first;
		}

		
	}

}