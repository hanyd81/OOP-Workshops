//name: Yadong Han
//ID 151799160
//email yhan61@myseneca.ca
//March 20, 2018

#include <iostream>
#include <cstring>
#include "ErrorState.h"

using namespace std;

namespace AMA {

	ErrorState::ErrorState(const char* errorMessage)
	{
		m_ermassage = nullptr;
		message(errorMessage);
		//cout << "ErrorState default constructor" << endl;
			
		
	}


	ErrorState::~ErrorState()
	{
		delete[] m_ermassage;
	}


	void ErrorState::clear()
	{
		delete[] m_ermassage;
		m_ermassage = nullptr;
	}

	/*bool ErrorState::isClear() const
	{
		return m_ermassage == nullptr;
	}*/

	void ErrorState::message(const char* str)
	{
		if (m_ermassage != str && str!=nullptr && str[0]!='\0') {
			delete[] m_ermassage;
			m_ermassage = nullptr;
			int len = strlen(str);
			m_ermassage = new char[len + 1];
			strncpy(m_ermassage, str, len);
			m_ermassage[len] = '\0';

		}
	}


	std::ostream& operator<<(std::ostream& out, const ErrorState& aError)
	{
		if (!aError.isClear())
			out << aError.message();
		return out;
	}
}