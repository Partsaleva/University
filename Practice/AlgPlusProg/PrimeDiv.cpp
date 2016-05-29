// PrimeDiv.cpp : Defines the entry point for the console application.
//
//–азлагане на число на прости делители

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;


int main()
{
	int n = 735;
	int i = 1;
	while (n!=1)
	{
		i++;
		int k = 0;
		while (n%i==0)
		{
			k++;
			n = n / i;
		}
		for (size_t j = 0; j < k; j++)
		{
			cout << i << ' ';
		}
	
	}


	return 0;
}

