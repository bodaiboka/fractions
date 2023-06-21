/*
 * Filename: main.cpp
 * Author: Richard Bodai
 * Email: bodaiboka@gmail.com
 * Description: A command-line program that takes operations on fractions as input and produces a fractionalresult.
 * 
 * Copyright (C) 2023 Richard Bodai
 * 
 */

#include "fractional_util.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	const auto prompt = "? ";

	cout 
    << "Input required: Please provide a mathematical expression to be evaluated." << endl
    << "Example format: '1/2 * 3&3/4'." << endl
    << "Mixed numbers shall be represented by whole&numerator/denominator."
    << "Legal operators shall be *, /, +, - (multiply, divide, add, subtract)." << endl
    << "Operands and operators shall be separated by one or more spaces." << endl
    << "Improper fractions, whole numbers, and negative numbers are allowed as operands." << endl;

	while (true) // we want to repeatedly prompt the user for input
	{
		string input;
		string result;

		cout << prompt;
		getline(cin, input); // read the next line and put it into input
		if (input == "exit")
		{
			cout << "You typed exit. Program quits." << endl;
			break; // user typed "exit" so we quit from the loop
		}
		try
		{
			result = produce_fractional_result(input); // parse the input and catch possible exceptions
			cout << "= " << result << endl;
		}
		catch(const runtime_error& e)
		{
			cerr << "Caught an exception: " << e.what() << endl;
		}
		catch(const invalid_argument& e)
		{
			cerr << "Caught an exception: " << "Invalid operand." << endl;
		}
	}

	return 0;
}