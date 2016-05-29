// CppPrimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	//Exercises Section 5.4.2
	/*Exercise 5.17: Given two vectors of ints, write a program to determine
	whether one vector is a prefix of the other.For vectors of unequal
	length, compare the number of elements of the smaller vector.For
	example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5,
	8, respectively your program should return true.*/

	vector<int>first = {0 , 2, 1, 2};
	vector<int> second = { 0, 1, 1, 2, 3, 5, 8};
	size_t smaller;

	if (first.size()<second.size())
	{
		smaller = first.size();
	}
	else
	{
		smaller = second.size();
	}
	
	for (auto i = 0; i !=smaller; i++)
	{
		if (first[i]!=second[i])
		{
			return false;
			break;
		}
	}
	return true;

	return 0;
}


