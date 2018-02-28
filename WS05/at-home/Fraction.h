// Name Yadong Han
// ID   151799160
//email yhan61@myseneca.ca

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: create namespace
namespace sict
{
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int m_numer;
		int m_deno;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;


	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int n, int d);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator + (const Fraction& rhs)const;
		Fraction operator * (const Fraction& b)const;
		bool operator == (const Fraction&b) const;
		bool operator != (const Fraction&b) const;
		Fraction operator += (const Fraction& b);
	};


}
#endif