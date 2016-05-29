// CppPrimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void recursivePrint(const vector<int> &vec, size_t i){
	if (i >= vec.size()) {
		return;
	}
	cout << vec[i] << " ";
	recursivePrint(vec, i + 1);
}


int main()
{	
	//Exercises Section 6.3
	//Exercise 6.33: Write a recursive function to print the contents of a vector
	vector<int> vecOfNum = {1,2,3,4,5,6,7,8,9,10};
	recursivePrint(vecOfNum, 0);

	


	return 0;
}


