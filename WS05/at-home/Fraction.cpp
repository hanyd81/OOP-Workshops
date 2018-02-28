// Name Yadong Han
// ID   151799160
//email yhan61@myseneca.ca

// TODO: insert header files
#include <iostream>
#include "Fraction.h"

// TODO: continue the namespace
using  namespace std;

namespace sict
{
	// TODO: implement the default constructor
	Fraction::Fraction()
	{
		m_numer = 0;
		m_deno = 1;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int n, int d)
	{
		if (n >= 0 && d > 0) {
			m_numer = n;
			m_deno = d;
			reduce();
		}
		else
			*this = Fraction();
	}
	// TODO: implement the max query
	int Fraction::max()const
	{
		return m_deno > m_numer ? m_deno : m_numer;
	}

	// TODO: implement the min query
	int Fraction::min()const
	{
		return m_deno < m_numer ? m_deno : m_numer;
	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce()
	{
		int divisor = this->gcd();
		m_deno = m_deno / divisor;
		m_numer = m_numer / divisor;
	}

	// TODO: implement the display query
	void Fraction::display() const
	{
		if (isEmpty()) {
			cout << "no fraction stored"<<endl;
		}
		else if (m_deno == 1) {
			cout << m_numer<<endl;
		}
		else {
			cout << m_numer << "/" << m_deno << endl;
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		return m_numer == 0;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+( const Fraction& rhs)const
	{
		if (isEmpty() || rhs.isEmpty()) {
			return Fraction();
			
		}
		else {
			Fraction c;
			c.m_deno = this->m_deno * rhs.m_deno;
			c.m_numer = this->m_numer *rhs.m_deno + this->m_deno*rhs.m_numer;
			c.reduce();
			return c;
			
		}
	}

	//implement the * operator
	Fraction Fraction::operator * (const Fraction& b)const
	{
		if (isEmpty() || b.isEmpty()) {
			return Fraction();
		}
		else {
			return Fraction(m_numer*b.m_numer, m_deno * b.m_deno);		
		}
	}

	//implement the == operator
	bool Fraction::operator == (const Fraction&b) const
	{
		if (isEmpty() || b.isEmpty())
			return false;
		else {
			return m_numer == b.m_numer && m_deno == b.m_deno;
		}
	}

	//implement the != operator
	bool Fraction::operator != (const Fraction&b) const
	{
		if (isEmpty() || b.isEmpty())
			return false;
		else {
			return !(*this==b);
		}
	}
	//implement the += operator
	Fraction Fraction::operator += (const Fraction& b)
	{
		*this = *this + b;
		return *this;
	}
}