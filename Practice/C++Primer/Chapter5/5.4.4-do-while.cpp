// CppPrimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	//Exercises Section 5.4.4
		/*Exercise 5.19: Write a program that uses a do while loop to repetitively
		request two strings from the user and report which string is less than the other.*/
	
	do
	{
		cout << "Enter two strings: " << endl;
		string str1, str2;
		cin >> str1 >> str2;
		if (str1<str2)
		{
			cout << "first string is less than the other" << endl;
		}
		else if (str1>str2)
		{
			cout << "second string is less than the other" << endl;
		}
		else
		{
			cout << "strings are equal" << endl;
		}
	} while (cin);

	return 0;
}


