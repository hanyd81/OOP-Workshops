//name Yadong Han
//ID 151799160
//email yhan61@myseneca.ca


//Contact.cpp

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {

	Contact::Contact()
	{
		m_name[0] = '\0';
		m_pPhones = nullptr;
		m_n = 0;
	}

	Contact::~Contact()
	{
		//cout << "delete " << this->m_pPhones << endl;
		delete[] m_pPhones;
	}

	Contact::Contact(const char* name, const long long* pPhones, int n)
	{
		set(name, pPhones, n);
		//cout << "create " << this->m_pPhones << endl;
	}

	bool Contact::isEmpty() const
	{
		return m_name[0] == '\0';
	}

	void Contact::display() const
	{
		long long temp;
		if (isEmpty())
			cout << "Empty contact!" << endl;
		else {
			cout << m_name << endl;
			for (int i = 0; i < m_n; ++i) {
				temp = m_pPhones[i];
				cout << "(+" << cCode(temp) << ") "
					<< aCode(temp) << " "
					<< pCode(temp) / 10000 << "-";
				cout.width(4);
				cout.fill('0');
				cout << pCode(temp) % 10000 << endl;

			}
		}
		cout.fill(' ');
	}

	int Contact::cCode(long long phone) const
	{
		return (int)(phone / 10000000000LL);
	}

	int Contact::aCode(long long phone) const
	{
		return (int)((phone - cCode(phone) * 10000000000LL) / 10000000LL);
	}
	int Contact::pCode(long long phone) const
	{
		return (int)(phone - cCode(phone) * 10000000000LL - aCode(phone) * 10000000LL);
	}

	bool Contact::validp(long long phone) const
	{
		bool valid = true;
		valid = valid && cCode(phone) > 0 && cCode(phone) <= 99;
		valid = valid && aCode(phone) >= 100 && aCode(phone) <= 999;
		valid = valid && pCode(phone) >= 1000000 && pCode(phone) <= 9999999;
		return valid;
	}

	void Contact::set(const char* name, const long long* pPhones, int n)
	{

		if (name != nullptr && name[0] != '\0') {
			int  vn = 0;
			long long temp;
			bool* validI = new bool[n];

			strncpy(m_name, name, maxName);
			m_name[maxName - 1] = '\0';

			for (int i = 0; i < n; i++) {
				temp = pPhones[i];
				if (validp(temp)) {
					validI[i] = true;
					vn++;
				}
				else validI[i] = false;
			}
			if (vn > 0) {
				m_pPhones = new long long[vn];
				int vi = 0;
				for (int i = 0; i < n; i++) {
					if (validI[i]) {
						m_pPhones[vi] = pPhones[i];
						vi++;
					}

				}
			}
			else {
				m_pPhones = nullptr;
			}
			m_n = vn;

			delete[] validI;
			validI = nullptr;
		}
		else {
			m_pPhones = nullptr;
			*this = Contact();
		}
	}



}