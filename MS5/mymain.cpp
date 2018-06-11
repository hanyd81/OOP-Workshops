

#include <iostream>
#include "iProduct.h"
#include "Product.h"
#include "Perishable.h"

#define NO 2

using namespace std;
using namespace AMA;
int main() {
	iProduct* p[NO];
	char ans;
	Perishable a;
	Product b;
	for (int i = 0; i < NO; i++) {
		cout << "perishable? ";
		cin >> ans;
		cin.ignore();
		if (ans == 'y' || ans == 'Y') {
			p[i] = new Perishable;
		}
		else {
			p[i] = new Product;
		}
		//p[i]->read(cin);
	}

	for (int i = 0; i < NO; i++) {
		cout << *p[i]<<endl;
	}


	for (int i = 0; i < NO; i++) {
		delete p[i];
	}


	return 0;
}