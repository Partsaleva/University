// CppPrimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;


int main()
{
	//Exercises Section 5.6.3
	/*Exercise 5.23: Write a program that reads two integers from the standard
	input and prints the result of dividing the first number by the second.*/
	/*Exercise 5.24 : Revise your program to throw an exception if the second
	number is zero.Test your program with a zero input to see what happens on
	your system if you don’t catch an exception.*/
	/*Exercise 5.25 : Revise your program from the previous exercise to use a
	try block to catch the exception.The catch clause should print a message
	to the user and ask them to supply a new number and repeat the code inside
	the try.*/

	cout << "reads two integers and prints the result of dividing the first number by the second"<<endl;
	int first, second;
	double result;
	while (cin >> first >> second)
	{
		try{
			if (second == 0)
			{
				throw std::invalid_argument("cant divide by 0");
			}
			result = first / second;
			cout << "result: " << result << endl;
		}
		catch (std::invalid_argument& err){
			cout << err.what() << endl;
			cout << "Try Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break; 
		}
	}
	

	return 0;
}


