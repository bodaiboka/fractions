#include "fraction.h"
#include "fractional_util.h"

string produce_fractional_result(string input)
{
	Expression exp;
	ostringstream oss;

	exp = extract_operands_op(input);
	Fraction f1(exp.operand1);
	Fraction f2(exp.operand2);
	Fraction result;
	switch(exp.op)
	{
	case '+':
		result = f1 + f2;
		break;
	case '-':
		result = f1 - f2;
		break;
	case '*':
		result = f1 * f2;
		break;
	case '/':
		result = f1 / f2;
		break;
	default:
		ostringstream oss;
		oss << "Invalid operator: '" << exp.op << "'." << endl;
		throw runtime_error(oss.str());
		break;
	}
	return result.toString();
}

Expression extract_operands_op(string input)
{
	Expression exp;
	istringstream iss(input);

	if (! (iss >> exp.operand1))
	{
		throw runtime_error("Missing first operand.");
	}
	if (! (iss >> exp.op))
	{
		throw runtime_error("Missing operator.");
	}
	if (! (iss >> exp.operand2))
	{
		throw runtime_error("Missing second operand.");
	}
	return exp;
}