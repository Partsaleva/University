// BigCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{

	//Exercises Section 3.3.2

//Exercise 3.14: Write a program to read a sequence of ints from cin and
//store those values in a vector.

	vector<int> numbers;
	int n;
	while (cin>>n)
	{
		numbers.push_back(n);
	}
	
	for (auto n : numbers)
	{
		cout<<n<<" ";
	}

//Exercise 3.15: Repeat the previous program but read strings this time.

	vector<std::string> strings;
	std::string s;
	while (cin>>s)
	{
		strings.push_back(s);
	}
	for (auto s : strings)
	{
		cout<<s<<" ";
	}

	return 0;
}

