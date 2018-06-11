//Name: Yadong Han
//ID: 151799160
//Email: yhan61@myseneca.ca

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account {

		double m_transFee;
		double m_monthFee;

		public:
			// TODO: constructor initializes account balance and transaction fee
			ChequingAccount(double balance, double trans_fee, double month_fee);

			// TODDO: credit adds +ve amount to the balance
			bool credit(double add);

			// TODO: debit subtracts a +ve amount from the balance
			bool debit(double subtract);

			// TODO: month end
			void monthEnd();

			// TODO: display inserts the account information into an ostream
			void display(std::ostream& out) const;

	};
}
#endif
