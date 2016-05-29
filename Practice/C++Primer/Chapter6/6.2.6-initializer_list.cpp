// CppPrimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
//too easy and too stupid task for this type

int tryInitList(std::initializer_list<int> tryL){
	int sum = 0;
	for (auto &num : tryL){
		sum += num;
	}
	return sum;
}

int main()
{
	/*Exercises Section 6.2.6
		Exercise 6.27: Write a function that takes an initializer_list<int>
		and produces the sum of the elements in the list.*/ 
	
	std::initializer_list<int> T = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << tryInitList(T) << endl;;

	
	return 0;
}


