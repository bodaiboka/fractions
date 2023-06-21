#ifndef FRACTION_H_
#define FRACTION_H_

#include <string>
using namespace std;

class Fraction {

private:
	int m_numerator;
	int m_denominator;
	int gcd(int a, int b); // to find the greatest common divider

public:
	Fraction(int whole = 0, int numerator = 0, int denominator = 1);
	Fraction(string); // we can create Fraction by a given string like: "whole&numerator/denominator" or "whole" or "numerator/denominator"
	void init(int, int, int);
	string toString();
	inline int numerator() const { return m_numerator; }
	inline int denominator() const { return m_denominator; }
	Fraction operator+(const Fraction& fraction) const;
	Fraction operator-(const Fraction& fraction) const;
	Fraction operator*(const Fraction& fraction) const;
	Fraction operator/(const Fraction& fraction) const;
};

#endif /* FRACTION_H_ */
