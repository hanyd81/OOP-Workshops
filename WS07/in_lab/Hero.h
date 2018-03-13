// Hero.h
//name Yadong Han
// ID 151799160
//Email yhan61@myseneca.ca

#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict {

	const int max_rounds = 100;

	class Hero {

		char m_name[41];
		int m_health;
		int m_attact; //need unsigned int??

	public:
		Hero();
		Hero(char* name, int health, int attack);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	};

	const Hero& operator*(const Hero& first, const Hero& second);



}



#endif // !SICT_HERO_H

