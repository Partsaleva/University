// ZeroCount.cpp : Defines the entry point for the console application.
//

//count zeros of product

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
	int arr[] = {25, 4, 20, 11, 13, 15};
	int count2 = 0;
	int count5 = 0;
	for (size_t i = 0; i < 6; i++)
	{
		while (arr[i] % 2 == 0)
		{
			count2++;
			arr[i] = arr[i] / 2;
		}
		while (arr[i] % 5 == 0)
		{
			count5++;
			arr[i] = arr[i] / 5;
		}
	}
	cout << min(count2, count5)<<endl;

	return 0;
}

