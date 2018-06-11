//name: Yadong Han
//ID 151799160
//email yhan61@myseneca.ca


#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

#include "Product.h"

using namespace std;

namespace AMA {

	void Product::name(const char* name)
	{
		int len;
		if (name != m_pname) {
			delete[] m_pname;
			m_pname = nullptr;
			if (name != nullptr) {
				len = strlen(name);
				m_pname = new char[len + 1];
				//cout << "m_pname get memory" << endl;
				strncpy(m_pname, name, len);
				m_pname[len] = '\0';
			}

		}
		
	}

	const char* Product::name() const
	{
		if (m_pname == nullptr || m_pname[0] == '\0')
			return nullptr;
		return m_pname;
	}

	//query function sku(), unit(), taxed(), price() write in line

	double Product::cost() const
	{
		if (m_taxable)
			return m_price * (1 + tax_rate);
		else
			return m_price;
	}

	void Product::message(const char* errorMess)
	{
		m_error.message(errorMess);
	}

	bool Product::isClear() const
	{
		return m_error.isClear();
	}

	void Product::set(const char* sku, const char* name, const char* unit,
		int hold, bool taxable, double price, int need)
	{
		if (sku != nullptr && sku[0] != '\0') {
			strncpy(m_sku, sku, max_sku_length);
			m_sku[max_sku_length] = '\0';
		}
		else
			m_sku[0] = '\0';

		if (unit != nullptr && unit[0] != '\0') {
			strncpy(m_unit, unit, max_unit_length);
			m_unit[max_unit_length] = '\0';
		}
		else
			m_unit[0] = '\0';

		m_hold = hold;
		m_taxable = taxable;
		m_price = price;
		m_need = need;
		this->name(name);
	}


	Product::Product(char type)
	{
		m_type = type;
		m_sku[0] = '\0';
		m_unit[0] = '\0';
		m_pname = nullptr;
		m_hold = 0;
		m_need = 0;
		m_price = 0;
		m_taxable = false;
		cout << this<<" Product default constructor" << endl;


	}

	Product::Product(const char* sku, const char* name, const char* unit,
		int hold, bool taxable, double price, int need)
	{
		m_type = 'N';
		set(sku, name, unit, hold, taxable, price, need);
		cout << this << " Product 7-arg constructor" << endl;
	}


	Product::Product(const Product& other)
	{
		m_pname = nullptr;
		*this = other;
		cout << this << " Product copy constructor" << endl;
	}

	Product& Product::operator=(const Product& other)
	{
		if (this != &other) {
			m_type = 'N';
			set(other.m_sku, other.m_pname, other.m_unit, other.m_hold, other.m_taxable, other.m_price, other.m_need);
			m_error.message(other.m_error.message());

		}
		return *this;
	}

	Product::~Product()
	{
		cout << this << " Product destructor" << endl;
		delete[] m_pname;
	}


	//non-member functions
	std::fstream& Product::store(std::fstream& file, bool newLine) const
	{
		if (!file) {
			std::cerr << "File is not open" << std::endl;
			return file;
		}
		char c = ',';
		file << type() << c << sku() << c ;
		if (name() != nullptr)
			file << m_pname << c;
		else
			file << "" << c;
		file << unit() << c << taxed() << c << price()<< c<< hold() << c << need();
		if (newLine)
			file << endl;
		return file;
	}

	std::fstream& Product::load(std::fstream& file)
	{
		if (!file) {
			cerr << "function load :file not open" << endl;
		}
		char d, c = ',';
		//char type;
		char sku[max_sku_length + 1];
		char unit[max_unit_length + 1];
		char name[max_name_length + 1];
		int hold;
		int need;
		double price;
		bool taxable;
		//file >> type;
		//file >> d;
		file.getline(sku, max_sku_length, c);
		file.getline(name, max_name_length, c);
		file.getline(unit, max_unit_length, c);
		file >> taxable;
		file >> d;
		file >> price;
		file >> d;
		file >> hold;
		file >> d;
		file >> need;
		if (file.fail()) {
			file.clear();
			return file;
		}

		set(sku, name, unit, hold, taxable, price, need);
		return file;

	}
	ostream& Product::write(ostream& os, bool linear) const
	{
		if (m_error.isClear()) {
			if (linear) {
				char deli = '|';
				os.setf(ios::left);
				os.width(max_sku_length);
				os << m_sku << deli;
				os.width(20);
				if (name() != nullptr)
					os << m_pname << deli;
				else
					os << "" << deli;
				os.unsetf(ios::left);

				os.width(7);
				os.setf(ios::fixed);
				os.precision(2);
				os << cost() << deli;
				os.unsetf(ios::fixed);
				os.precision(6);

				os.width(4);
				os << quantity() << deli;

				os.setf(ios::left);
				os.width(10);
				os << unit() << deli;
				os.unsetf(ios::left);

				os.width(4);
				os << need() << deli;                        //no endl 
			}
			else {
				os << " Sku: " << sku() << endl;
				if (name() == nullptr)
					os << " Name (no spaces):" << endl;
				else
					os << " Name (no spaces): " << name() << endl;
				os.setf(ios::fixed);
				os.precision(2);
				os << " Price: " << price() << endl;
				os << " Price after tax: ";
				if (taxed())
					 os << cost() << endl;
				else
					os << " N/A" << endl;
				os.unsetf(ios::fixed);
				os.precision(6);
				os << " Quantity on Hand: " << hold() <<" " << unit()<<endl;
				os << " Quantity needed: " << need() ;
			}
		}
		else {
			os << m_error;
		}
		return os;
	}

	std::istream& Product::read(std::istream& is)
	{
		string raw, temp;
		char sku[max_sku_length + 1];
		char unit[max_unit_length + 1];
		char name[max_name_length + 1];
		char taxed;
		int hold;
		int need;
		double price;
		bool taxable;
		m_error.clear();

		cout << " Sku: ";
		getline(is, raw);
		if (raw != "") {
			strncpy(sku, raw.c_str(), max_sku_length);
			sku[max_sku_length] = '\0';
		}
		else
			return is;

		cout << " Name (no spaces): ";
		getline(is, raw);
		strncpy(name, raw.c_str(), max_name_length);
		name[max_name_length] = '\0';

		cout << " Unit: ";
		getline(is, raw);
		strncpy(unit, raw.c_str(), max_unit_length);
		name[max_unit_length] = '\0';

		cout << " Taxed? (y/n): ";
		is >> taxed;
		if (taxed == 'y' || taxed == 'Y')
			taxable = true;
		else if (taxed == 'n' || taxed == 'N')
			taxable = false;
		else {
			this->m_error.message("Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);
			return is;
		}

		cout << " Price: ";
		is >> price;
		if (is.fail()) {
			this->m_error.message("Invalid Price Entry");
			is.setstate(std::ios::failbit);
			return is;
		}

		cout << " Quantity on hand: ";
		is >> hold;
		if (is.fail()) {
			this->m_error.message("Invalid Quantity Entry");
			is.setstate(std::ios::failbit);
			return is;
		}

		cout << " Quantity needed: ";
		is >> need;
		if (is.fail()) {
			this->m_error.message("Invalid Quantity Needed Entry");
			is.setstate(std::ios::failbit);
			return is;
		}
		is.ignore(100, '\n');

		set(sku, name, unit, hold, taxable, price, need);
		return is;
	}

	bool Product::operator==(const char* sku) const
	{
		if (strcmp(m_sku, sku) == 0)
			return true;
		else
			return false;
	}

	double Product::total_cost() const
	{
		if (m_taxable)
			return m_price * (1 + tax_rate) * m_hold;
		else
			return m_price * m_hold;
	}

	void Product::quantity(int onHand)
	{
		m_hold = onHand;
	}

	bool Product::isEmpty() const
	{
		return m_sku[0] == '\0';
	}

	int Product::qtyNeeded() const
	{
		return m_need;
	}

	int Product::quantity() const
	{
		return m_hold;
	}

	bool Product::operator>(const char* sku) const
	{
		return strcmp(this->sku(), sku) > 0;
	}

	bool Product::operator>(const iProduct& other) const
	{
		return strcmp(this->name(), other.name()) > 0;
	}

	int Product::operator+=(int add)
	{
		if (add > 0) {
			m_hold += add;
		}
		return m_hold;
	}

	double operator+=(double& tCost, const iProduct& p)
	{
		tCost += p.total_cost();
		return tCost;
	}

	
	std::ostream& operator<<(std::ostream& out, const iProduct& p)
	{
		p.write(out, true);
		return out;
	}
	std::istream& operator>>(std::istream& in, iProduct& p)
	{
		p.read(in);
		return in;
	}
}