//name: Yadong Han
//ID: 151799160
//email: yhan61@myseneca.ca

#ifndef SICT_DATA_H
#define SICT_DATA_H



#include <iostream>


namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	template <typename T>
	T max(const T* data, int n) {
		T big = data[0];
		for (int i = 1; i < n; ++i) {
			if (data[i] > big)
				big = data[i];
		}
		return big;
	}

	// min returns the smallest item in data
	template <typename T>
	T min(const T* data, int n) {
		T small = data[0];
		for (int i = 1; i < n; ++i) {
			if (data[i] < small)
				small = data[i];
		}
		return small;
	}

        
	// sum returns the sum of n items in data
	template <typename T>
	T sum(const T* data, int n) {
		T total = data[0];
		for (int i = 1; i < n; ++i) {
				total += data[i];
		}
		return total;
	}
   
	// average returns the average of n items in data
	template <typename T>
	double average(const T* data, int n) {
		T total = data[0];
		for (int i = 1; i < n; ++i) {
			total += data[i];
		}
		return static_cast<double>(total)/n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		char d;
		
		for (int i = 0; i < n; ++i) {
			input >> d;
			input >> data[i];
		}
		if (input.fail())
			return false;
		else
			return true;
	}
	
	// display inserts n items of data into std::cout
	template <typename T>
	void display(const char* name, const T* data, int n) {
		cout.width(20);
		cout << name;
		for (int i = 0; i < n; i++) {
			cout.width(15);
			cout << data[i];
		}
		cout << endl;
	}




	template <typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
	
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif // !SICT_DATA_H
