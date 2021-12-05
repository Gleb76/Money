#include <iostream>
#include "Money.h"

int main()
{
	long pd, sh;
	double p;
	Money a, b, c;
	cout << "Enter pd1, sh1, p1: " << endl;
	cin >> pd >> sh >> p;

	try {

		a.setPd(pd);
		a.setSh(sh);
		a.setP(p);

	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
		return 0;
	}

	cout << "Enter pd2, sh2, p2: " << endl;
	cin >> pd >> sh >> p;
	try {
		b.setPd(pd);
		b.setSh(sh);
		b.setP(p);

	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
		return 0;
	}

	//cout << a << endl;

	cout << "a + b: " << a + b << endl;
	cout << "a - b: " << a - b << endl;
	a += b;
	cout << "a += b: " << a << endl;
	a -= b;
	cout << "a -= b: " << a << endl;
	if (a == b) {
		cout << "a = b: True " << endl;
	}
	else {
		cout << "a = b: False " << endl;
	}

	if (a != b) {
		cout << "a != b: True " << endl;
	}
	else {
		cout << "a != b: False " << endl;
	}

	if (a > b) {
		cout << "a > b: True " << endl;
	}
	else {
		cout << "a > b: False " << endl;
	}

	if (a < b) {
		cout << "a < b: True " << endl;
	}
	else {
		cout << "a < b: False " << endl;
	}


	if (a <= b) {
		cout << "a <= b: True " << endl;
	}
	else {
		cout << "a <= b: False " << endl;
	}

	if (a >= b) {
		cout << "a >= b: True " << endl;
	}
	else {
		cout << "a >= b: False " << endl;
	}



}

