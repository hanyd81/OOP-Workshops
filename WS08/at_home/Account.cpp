//Name: Yadong Han
//ID: 151799160
//Email: yhan61@myseneca.ca

#include "Account.h"

namespace sict {
	double Account::balance() const
	{
		return m_balance;
	}

	// TODO: constructor initializes account balance, defaults to 0.0 
	Account::Account(double balance)
	{
		if (balance >= 0)
			m_balance = balance;
		else
			m_balance = 0;
	}

	// TODO: credit adds +ve amount to the balance 
	bool Account::credit(double add)
	{
		if (add > 0) {
			m_balance += add;
			return true;
		}
		else {
			return false;
		}

	}

	// TODO: debit subtracts a +ve amount from the balance
	bool Account::debit(double subtract)
	{
		if (subtract > 0) {
			m_balance -= subtract;
			return true;
		}
		else {
			return false;
		}
	}
}
