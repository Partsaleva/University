// AlgPlus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void separNum(size_t n){
	size_t digits[10];
	size_t k = 0;
	while (n > 0){
		digits[k] = n % 10;
		n /= 10;
		k++;
	}
	for (size_t i = k; i>0; i--)
	{
		cout << digits[i-1] << ' ';

	}
	cout << '\n';
}

void printN(size_t n)
{
	if (n >= 10){
		printN(n / 10);
	}
	cout << n % 10<<' ';
}

const unsigned n = 5;
void printRed(unsigned k, unsigned long result)
{
	cout<< result<<' ';
	if (k < n) {
		printRed(k + 1, result * 10);
	}
	cout<< result<<' ';
}
int main()
{
	separNum(12892);
	printN(12345);
	cout << endl;
	printRed(1, 10);
	return 0;
}

