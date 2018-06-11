//Name: Yadong Han
//ID: 151799160
//Email: yhan61@myseneca.ca

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double m_inRate;

	public:
		// TODO: constructor initializes balance and interest rate
		SavingsAccount(double balance, double rate);

		// TODO: perform month end transactions
		virtual void monthEnd();

		// TODO: display inserts the account information into an ostream			
		virtual void display(std::ostream& out) const;
	};
}
#endif
