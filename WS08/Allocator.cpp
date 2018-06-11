//Name: Yadong Han
//ID: 151799160
//Email: yhan61@myseneca.ca

#include "iAccount.h"
#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	const double interest_rate = 0.05;


	// TODO: Allocator function
	iAccount* CreateAccount(const char* account, double balance)
	{

		if (account[0] == 'S') {
			iAccount* pAccount = new SavingsAccount(balance, interest_rate);
			return pAccount;
		}
		else {
			return nullptr;
		}
	}








}
