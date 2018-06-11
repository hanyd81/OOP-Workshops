//Name: Yadong Han
//ID: 151799160
//Email: yhan61@myseneca.ca
#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	// TODO: constructor initializes balance and interest rate
	SavingsAccount::SavingsAccount(double balance, double rate) :Account(balance)
	{
		if (rate > 0)
			m_inRate = rate;
		else 
			m_inRate = 0;
	}

	// TODO: perform month end transactions
	void SavingsAccount::monthEnd()
	{
		double interest = balance()*m_inRate;
		credit(interest);
	}

	// TODO: display inserts the account information into an ostream			
	void SavingsAccount::display(std::ostream& out) const
	{
		out << "Account type: Savings"<<endl;
		out.setf(ios::fixed);
		out.precision(2);
		out << "Balance: $" << balance() << endl;
		out << "Inerest Rate (%): " << m_inRate*100 << endl;
		out.unsetf(ios::fixed);
		out.precision(6);
	}

}