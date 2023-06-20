#ifndef FRACTION_H_
#define FRACTION_H_

#include <string>
using namespace std;

class Fraction {

private:
	int m_nominator;
	int m_denominator;
	int gcd(int a, int b); // to find the greatest common divider

public:
	Fraction(int whole = 0, int nominator = 0, int denominator = 1);
	Fraction(string); // we can create Fraction by a given string like: "whole&nominator/denominator" or "whole" or "nominator/denominator"
	void init(int, int, int);
	string toString();
	inline int nominator() const { return m_nominator; }
	inline int denominator() const { return m_denominator; }
	Fraction operator+(const Fraction& fraction) const;
	Fraction operator-(const Fraction& fraction) const;
	Fraction operator*(const Fraction& fraction) const;
	Fraction operator/(const Fraction& fraction) const;
};

#endif /* FRACTION_H_ */
