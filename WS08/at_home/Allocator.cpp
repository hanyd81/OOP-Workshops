//Name: Yadong Han
//ID: 151799160
//Email: yhan61@myseneca.ca

#include "iAccount.h"
#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	const double interest_rate = 0.05;
	const double transaction_fee = 0.5;
	const double monthly_fee = 2.00;

	// TODO: Allocator function
	iAccount* CreateAccount(const char* account, double balance)
	{

		if (account[0] == 'S') {
			iAccount* pAccount = new SavingsAccount(balance, interest_rate);
			return pAccount;
		}
		else if (account[0] == 'C') {
			iAccount* pAccount = new ChequingAccount(balance, transaction_fee, monthly_fee );
			return pAccount;
		}
		else {
			return nullptr;
		}
	}








}
