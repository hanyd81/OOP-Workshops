//name: Yadong Han
//ID: 151799160
//email: yhan61@myseneca.ca

#include <iostream>
#include <fstream>
#include "Product.h"
#include "Date.h"
#include "Perishable.h"


using namespace std;
namespace AMA {

	Perishable::Perishable() : Product('P'){ cout << this << " Perishable default constructor" << endl; }
	Perishable::~Perishable() {cout << this << " Perishable default destructor" << endl; }


	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	{
		char d = ',';
		Product::store(file, false);
		file << d;
		file << expiry();
		if (newLine)
			file << endl;
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file)
	{
		char d;
		Product::load(file);
		if (!file.fail())
			file >> d;
			file >> m_date;
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const
	{
		Product::write(os, linear);
		if (!m_date.bad() && !this->isEmpty()) {
			if (linear)
				os << expiry();
			else
			{
				os << endl << " Expiry date: " << expiry();
			}
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is)
	{
		Date temp;
		Product::read(is);
		if (!is.fail()) {
			cout << " Expiry date (YYYY/MM/DD): ";
			is >> temp;
			if (temp.bad()) {
				is.istream::setstate(std::ios::failbit);
				switch (temp.errCode()) {
				case CIN_FAILED: 
					message("Invalid Date Entry");
					break;
				case YEAR_ERROR:
					message("Invalid Year in Date Entry");
					break;
				case MON_ERROR:
					message("Invalid Month in Date Entry");
					break;
				case DAY_ERROR:
					message("Invalid Day in Date Entry");
					break;
				}
			}
			m_date = temp;
		}
		return is;
	}

	const Date& Perishable::expiry() const
	{
		return m_date;
	}
}