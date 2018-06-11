//Name: Yadong Han
//ID: 151799160
//Email: yhan61@myseneca.ca

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account:public iAccount {

		double m_balance;
	protected:
		double balance() const;

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double balance = 0.0);

		// TODO: credit adds +ve amount to the balance 
		virtual bool credit(double add);

		// TODO: debit subtracts a +ve amount from the balance
		virtual bool debit(double subtract);
	};


}
#endif
