//name Yadong Han
//ID 151799160
//email yhan61@myseneca.ca


//Contact.h

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

const int maxName = 20;

namespace sict {

	class Contact {
		char m_name[maxName];
		long long* m_pPhones;
		int m_n;

		int cCode(long long phone) const;
		int aCode(long long phone) const;
		int pCode(long long phone) const;
		bool validp(long long phone) const;
		void set(char* name, long long* pPhones, int n);
	
	public:	
		Contact();
		Contact(char* name, long long* pPhones, int n);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};

	

}

#endif // !SICT_CONTACT_H
