#include "Money.h"
#include <iostream>
using namespace std;
long getSum(const Money& x) { 
	long pens = 2 * (20 * 12 * x.getPd() + 12 * x.getSh() + x.getP());

	return pens;
}

Money::Money(long a, long b, double c)
{
	pd = a;
	sh = b;
	p = c;

	if (sh >= 20 || p >= 12) {
		throw std::exception("Wrong number of money !!!");
	}
}

Money::Money()
{
	sh = 0;
	pd = 0;
	p = 0;
}

void Money::setPd(long a)
{
	pd = a;
}

long Money::getPd() const
{
	return pd;
}

void Money::setSh(long b)
{
	sh = b;
	if (sh >= 20) {
		throw std::exception("Wrong number of money!!!");
	}
}


long Money::getSh() const
{
	return sh;
}

void Money::setP(double c)
{
	p = c;
	long z = p * 10;

	if (p >= 12) {
		throw std::exception("Wrong number of money !!!");
	}

	if ((z % 10 != 5) && (z % 10 != 0)) {
		throw std::exception("Wrong number of money !!!");
	}
}


double Money::getP() const
{
	return p;
}

Money Money::operator+(const Money& m)
{
	long a, b;
	double c;
	a = pd + m.getPd();
	b = sh + m.getSh();
	c = p + m.getP();

	if (c >= 12) {
		c -= 12;
		b++;
	}

	if (b >= 20) {
		b -= 20;
		a++;
	}

	return Money(a, b, c);
}




Money Money::operator-(const Money& m)
{
	long a, b;
	double c;
	bool halfp;
	int pens1, pens2, diff;
	pens1 = getSum(*this);
	pens2 = getSum(m);

	diff = pens1 - pens2;

	if (diff % 2 == 1 || diff % 2 == -1) {
		halfp = true;
	}
	else {
		halfp = false;
	}




	if (diff > 0) {
		diff /= 2;
		a = diff / (20 * 12);
		diff = diff % (20 * 12);
		b = diff / 12;
		c = diff % 12;
		if (halfp) {
			c += 0.5;
		}

		return Money(a, b, c);


	}
	else {
		if (diff == -1) {
			return Money(0, 0, -0.5);

		}
		else {
			diff /= 2;
			diff *= -1;
			a = diff / (20 * 12);

			diff = diff % (20 * 12);
			b = diff / 12;
			c = diff % 12;

			if (halfp) {
				c += 0.5;
			}

			if (a != 0) {
				a *= -1;
			}
			else if (b != 0) {
				b *= -1;
			}
			else if (c != 0) {
				c *= -1;
			}

			return Money(a, b, c);
		}
	}

	return Money(a, b, c);

}

Money Money::operator+=(const Money& m)
{
	double a, b, c;
	a = pd + m.pd;
	b = sh + m.sh;
	c = p + m.p;

	if (c >= 12) {
		c -= 12;
		b++;
	}

	if (b >= 20) {
		b -= 20;
		a++;
	}

	pd = a;
	sh = b;
	p = c;
	return Money(a, b, c);
}

Money Money::operator-=(const Money& m)
{
	//return (*this - m);

	long a, b, pens1, pens2, diff;
	double c;
	bool halfp;

	pens1 = getSum(*this);
	pens2 = getSum(m);

	diff = pens1 - pens2;

	if (diff % 2 == 1 || diff % 2 == -1) {
		halfp = true;
	}
	else {
		halfp = false;
	}

	if (diff > 0) {
		diff /= 2;
		a = diff / (20 * 12);
		diff = diff % (20 * 12);
		b = diff / 12;
		c = diff % 12;
		if (halfp) {
			c += 0.5;
		}

		pd = a;
		sh = b;
		p = c;
		return Money(a, b, c);


	}
	else {
		if (diff == -1) {
			return Money(0, 0, -0.5);

		}
		else {
			diff /= 2;
			diff *= -1;
			a = diff / (20 * 12);
			a *= -1;
			diff = diff % (20 * 12);
			b = diff / 12;
			c = diff % 12;
			if (halfp) {
				c += 0.5;
			}

			pd = a;
			sh = b;
			p = c;
			return Money(a, b, c);

		}

	}
}

bool Money::operator==(const Money& m) const
{
	return (pd == m.pd && sh == m.sh && p == m.p);
}

bool Money::operator!=(const Money& m) const
{
	return (pd != m.pd || sh != m.sh || p != m.p);
}

bool Money::operator>(const Money& m) const
{
	long pens1, pens2;

	pens1 = getSum(*this);
	pens2 = getSum(m);

	return(pens1 > pens2);
}

bool Money::operator<(const Money& m) const
{
	return(!(*this > m) && !(*this == m));
}

bool Money::operator>=(const Money& m) const
{
	return (!(*this < m));
}

bool Money::operator<=(const Money& m) const
{
	return ((*this < m) || (m == *this));
}




std::ostream& operator<<(std::ostream& os, const Money& m)
{
	if (m.pd == 0 && m.sh == 0 && m.p == 0) {
		os << m.p << "p.";
	}
	if (m.pd != 0) {
		os << m.pd << "pd.";
	}
	if (m.sh != 0) {
		os << m.sh << "sh.";
	}
	if (m.p != 0) {
		os << m.p << "p.";
	}

	return os;
}


