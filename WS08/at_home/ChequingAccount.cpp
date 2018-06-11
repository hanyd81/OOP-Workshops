// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
//Name: Yadong Han
//ID: 151799160
//Email: yhan61@myseneca.ca
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount(double balance, double trans_fee, double month_fee) :Account(balance)
	{
		if (trans_fee > 0)
			m_transFee = trans_fee;
		else
			m_transFee = 0;
		if (month_fee > 0)
			m_monthFee = month_fee;
		else
			m_monthFee = 0;
	}



	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double add)
	{
		if (add > 0) {
			Account::credit(add - m_transFee);
			return true;
		}
		else
			return false;
	}



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double subtract)
	{
		if (subtract > 0) {
			Account::debit(subtract + m_transFee);
			return true;
		}
		else
			return false;
	}

	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd()
	{
		debit(m_monthFee);
	}



	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& out) const
	{
		out << "Account type: Chequing" << endl;
		out.setf(ios::fixed);
		out.precision(2);
		out << "Balance: $" << balance() << endl;
		out << "Per Transaction Fee: " << m_transFee << endl;
		out << "Monthly Fee: " << m_monthFee << endl;
		out.unsetf(ios::fixed);
		out.precision(6);
	}



}