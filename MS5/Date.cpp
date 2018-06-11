// name Yadong Han
// ID 151799160
// email yhan61@myseneca.ca



#include<iostream>
#include "Date.h"

using namespace std;

namespace AMA {

	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode)
	{
		m_error = errorCode;
	}

	Date::Date()
	{
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_compare = 0;
		m_error = NO_ERROR;
	}

	Date::Date(int year, int month, int day)
	{
		bool valid = true;
		*this = Date();
		if (year > max_year || year < min_year) {
			errCode(YEAR_ERROR);
			valid = false;
		}
		else
			if (month > 12 || month < 1) {
				errCode( MON_ERROR);
				valid = false;
			}
			else if (day<1 || day> mdays(month, year)) {
				errCode (DAY_ERROR);
				valid = false;
			}

			if (valid) {
				m_year = year;
				m_month = month;
				m_day = day;
				errCode(NO_ERROR);
				m_compare = year * 372 + month * 13 + day;
			}

	}

	bool Date::operator==(const Date& rhs) const
	{
		if (m_year == 0 || rhs.m_year == 0)
			return false;
		return m_compare == rhs.m_compare;
	}

	bool Date::operator!=(const Date& rhs) const
	{
		if (m_year == 0 || rhs.m_year == 0)
			return false;
		return m_compare != rhs.m_compare;
	}

	bool Date::operator<(const Date& rhs) const
	{
		if (m_year == 0 || rhs.m_year == 0)
			return false;
		return m_compare < rhs.m_compare;
	}

	bool Date::operator>(const Date& rhs) const
	{
		if (m_year == 0 || rhs.m_year == 0)
			return false;
		return m_compare > rhs.m_compare;
	}

	bool Date::operator<=(const Date& rhs) const
	{
		if (m_year == 0 || rhs.m_year == 0)
			return false;
		return (*this == rhs || *this < rhs);
	}

	bool Date::operator>=(const Date& rhs) const
	{
		if (m_year == 0 || rhs.m_year == 0)
			return false;
		return (*this == rhs || *this > rhs);
	}


	int Date::errCode() const
	{
		return m_error;
	}

	bool Date::bad() const
	{
		return errCode() != NO_ERROR;
	}

	istream& Date::read(istream& istr)
	{
		char a, b;
		int year, month, day;
		istr >> year;
		istr >> a;
		istr >> month;
		istr >> b;
		istr >> day;
		if (istr.fail())
			errCode(CIN_FAILED);
		else {
			*this = Date(year, month, day);
		}
		return istr;
	}

	ostream& Date::write(ostream& ostr) const
	{
		char oldfill;
		oldfill=ostr.fill('0');
		//ostr.width(4);
		ostr << m_year << "/";
		ostr.width(2);
		ostr << m_month << "/";
		ostr.width(2);
		ostr << m_day;
		ostr.fill(oldfill);
		return ostr;
	}

	ostream& operator<<(ostream& out, const Date& mydate)
	{
		mydate.write(out);
		return out;
	}
	istream& operator>>(istream& in, Date& mydate)
	{
		mydate.read(in);
		return in;
	}

}
