//name: Yadong Han
//ID 151799160
//email yhan61@myseneca.ca
//March 20, 2018

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

#include<iostream>

namespace AMA {

	class ErrorState
	{
		char* m_ermassage;

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();

		void clear();
		bool isClear() const {return m_ermassage == nullptr;}
		void message(const char* str);
		const char* message() const { return m_ermassage; }
	};

	std::ostream& operator<<(std::ostream& out, const ErrorState& aError);
}

#endif // !AMA_ERRORSTATE_H
