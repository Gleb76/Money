#pragma once
#include <iostream>
using namespace std;
class Money
{
private:
	long  pd, sh;
	double p;
public:
	Money(long a, long b, double c);
	Money();

	void setPd(long a);
	long getPd() const;

	void setSh(long b);
	long getSh() const;

	void setP(double c);
	double getP() const;

	Money operator+(const Money&);
	Money operator-(const Money&);
	Money operator+=(const Money&);
	Money operator-=(const Money&);
	bool operator == (const Money&) const;
	bool operator != (const Money&) const;
	bool operator > (const Money&) const;
	bool operator < (const Money&) const;
	bool operator >= (const Money&) const;
	bool operator <= (const Money&) const;

	friend std::ostream& operator <<(std::ostream& os, const Money& m);

};

