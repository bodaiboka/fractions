#include "fraction.h"
#include <stdexcept>
#include <sstream>

void Fraction::init(int whole, int numerator, int denominator)
{
	m_numerator = abs(numerator) + abs(whole) * abs(denominator);
	m_denominator = denominator;
	m_numerator *= (whole < 0 || numerator < 0) ? -1 : 1;
	if (m_denominator == 0)
	{
		throw runtime_error("Division by zero is not allowed.");
	}
}

Fraction::Fraction(int whole, int numerator, int denominator)
{
	init(whole, numerator, denominator);
}

Fraction::Fraction(string expression)
{
	int whole, numerator, denominator;
	size_t andPos = expression.find('&');
	size_t slashPos = expression.find('/');

	if (andPos != string::npos)
	{
		whole = stoi(expression.substr(0, andPos));
		if (slashPos != string::npos)
		{
			numerator = stoi(expression.substr(andPos + 1, slashPos - andPos +1));
			denominator = stoi(expression.substr(slashPos+1));
		}
		else
		{
			throw runtime_error("The expression contains the '&' character, indicating that a fraction was expected, but the '/' character, which is required for fraction, is missing. Please check the expression syntax and ensure that if the '&' character is used, it's followed by a fraction which contains '/'.");
		}
	}
	else
	{
		if (slashPos != string::npos)
		{
			whole = 0;
			numerator = stoi(expression.substr(0, slashPos));
			denominator = stoi(expression.substr(slashPos+1));
		}
		else
		{
			whole = stoi(expression);
			numerator = 0;
			denominator = 1; // only technical representation: since numerator is 0 the fraction itself is also 0
		}
	}
	if ((denominator < 0) || (whole != 0 && (numerator < 0 || denominator < 0)))
	{
		throw runtime_error("A negative sign is detected in an incorrect position. Negative signs are allowed only to the left of operands. Please check the expression and ensure that any negative sign is placed immediately before its associated operand.");
	}
	init(whole, numerator, denominator);
}

string Fraction::toString()
{
	int whole, numerator, gc;
	whole = 0;
	gc = gcd(abs(m_numerator), abs(m_denominator));
	m_numerator /= gc;
	m_denominator /= gc;
	numerator = abs(m_numerator);
	if (abs(m_numerator) >= abs(m_denominator))
	{
		whole += abs(m_numerator) / abs(m_denominator);
		numerator = abs(m_numerator) % abs(m_denominator);
	}
	ostringstream oss;
	oss << ((m_numerator < 0 && m_denominator > 0) || (m_numerator > 0 && m_denominator < 0) ? "-" : "");
	oss << (whole != 0 ? to_string(whole) : "");
	oss << (whole != 0 && numerator != 0 ? "&" : "");
	oss << (numerator != 0 ? to_string(abs(numerator)) + "/" + to_string(m_denominator) : "");
	oss << (whole == 0 && numerator == 0 ? "0" : "");
	return oss.str();
}

Fraction Fraction::operator+(const Fraction& fraction) const
{
	return Fraction(0, m_numerator * fraction.denominator() + m_denominator * fraction.numerator(), m_denominator * fraction.denominator());
}
Fraction Fraction::operator-(const Fraction& fraction) const
{
	return Fraction(0, m_numerator * fraction.denominator() - m_denominator * fraction.numerator(), m_denominator * fraction.denominator());
}
Fraction Fraction::operator*(const Fraction& fraction) const
{
	return Fraction(0, m_numerator * fraction.numerator(), m_denominator * fraction.denominator());
}
Fraction Fraction::operator/(const Fraction& fraction) const
{
	return Fraction(0, m_numerator * fraction.denominator(), m_denominator * fraction.numerator());
}

int Fraction::gcd(int a, int b)
{
	if(a%b == 0)
    {
		return b;
	}
	else
    {
		return gcd(b, a%b);
	}
}
