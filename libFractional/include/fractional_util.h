#ifndef FRACTIONAL_UTIL_
#define FRACTIONAL_UTIL_

#include <sstream>
#include <string>
using namespace std;

typedef struct expression
{
	string operand1;
	string operand2;
	char op;
} Expression;

string produce_fractional_result(string);
Expression extract_operands_op(string);

#endif /* FRACTIONAL_UTIL_ */