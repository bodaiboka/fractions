#include "include/fraction.h"
#include <stdexcept>
#include <sstream>

void Fraction::init(int whole, int nominator, int denominator)
{
	m_nominator = abs(nominator) + abs(whole) * abs(denominator);
	m_denominator = denominator;
	m_nominator *= (whole < 0 || nominator < 0) ? -1 : 1;
	if (m_denominator == 0)
	{
		throw runtime_error("Division by zero is not allowed.");
	}
}

Fraction::Fraction(int whole, int nominator, int denominator)
{
	init(whole, nominator, denominator);
}

Fraction::Fraction(string expression)
{
	int whole, nominator, denominator;
	size_t andPos = expression.find('&');
	size_t slashPos = expression.find('/');

	if (andPos != string::npos)
	{
		whole = stoi(expression.substr(0, andPos));
		if (slashPos != string::npos)
		{
			nominator = stoi(expression.substr(andPos + 1, slashPos - andPos +1));
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
			nominator = stoi(expression.substr(0, slashPos));
			denominator = stoi(expression.substr(slashPos+1));
		}
		else
		{
			whole = stoi(expression);
			nominator = 0;
			denominator = 1; // only technical representation: since nominator is 0 the fraction itself is also 0
		}
	}
	if ((denominator < 0) || (whole != 0 && (nominator < 0 || denominator < 0)))
	{
		throw runtime_error("A negative sign is detected in an incorrect position. Negative signs are allowed only to the left of operands. Please check the expression and ensure that any negative sign is placed immediately before its associated operand.");
	}
	init(whole, nominator, denominator);
}

string Fraction::toString()
{
	int whole, nominator, gc;
	whole = 0;
	gc = gcd(abs(m_nominator), abs(m_denominator));
	m_nominator /= gc;
	m_denominator /= gc;
	nominator = abs(m_nominator);
	if (abs(m_nominator) >= abs(m_denominator))
	{
		whole += abs(m_nominator) / abs(m_denominator);
		nominator = abs(m_nominator) % abs(m_denominator);
	}
	ostringstream oss;
	oss << ((m_nominator < 0 && m_denominator > 0) || (m_nominator > 0 && m_denominator < 0) ? "-" : "");
	oss << (whole != 0 ? to_string(whole) : "");
	oss << (whole != 0 && nominator != 0 ? "&" : "");
	oss << (nominator != 0 ? to_string(abs(nominator)) + "/" + to_string(m_denominator) : "");
	oss << (whole == 0 && nominator == 0 ? "0" : "");
	return oss.str();
}

Fraction Fraction::operator+(const Fraction& fraction) const
{
	return Fraction(0, m_nominator * fraction.denominator() + m_denominator * fraction.nominator(), m_denominator * fraction.denominator());
}
Fraction Fraction::operator-(const Fraction& fraction) const
{
	return Fraction(0, m_nominator * fraction.denominator() - m_denominator * fraction.nominator(), m_denominator * fraction.denominator());
}
Fraction Fraction::operator*(const Fraction& fraction) const
{
	return Fraction(0, m_nominator * fraction.nominator(), m_denominator * fraction.denominator());
}
Fraction Fraction::operator/(const Fraction& fraction) const
{
	return Fraction(0, m_nominator * fraction.denominator(), m_denominator * fraction.nominator());
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
