////name: Yadong Han
//ID 151799160
//email yhan61@myseneca.ca


#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <fstream>
#include <iostream>
#include "iProduct.h"
#include "ErrorState.h"

namespace AMA {

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;


	class Product: public iProduct
	{
		char m_type;
		char m_sku[max_sku_length +1];
		char m_unit[max_unit_length +1];
		char* m_pname;
		int m_hold;
		int m_need;
		double m_price;
		bool m_taxable;
		ErrorState m_error;

		void set(const char* sku, const char* name, const char* unit,
			int hold = 0, bool taxable = true, double price = 0, int need = 0); //self defined helper function

	protected:
		void name(const char*);
		const char* name() const;
		const char* sku()const { return m_sku; };
		const char* unit()const { return m_unit; };
		bool taxed()const { return m_taxable; };
		double price()const { return m_price; };
		double cost() const;
		void message(const char*);
		bool isClear() const;

		char type()const { return m_type; };		// self defined query
		int hold()const { return m_hold; };			// self defined query
		int need()const { return m_need; };			// self defined query
		
	public:
		Product(char type='N');
		Product(const char* sku, const char* name, const char* unit, 
			int hold = 0, bool taxable = true, double price = 0, int need = 0);
		Product(const Product& other);
		Product& operator=(const Product& other);
		virtual ~Product();                        //need virtual destructor?
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char* sku) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* sku) const;
		bool operator>(const iProduct& other) const;
		int operator+=(int add);
	};
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double& tCost, const iProduct& p);




}

#endif

