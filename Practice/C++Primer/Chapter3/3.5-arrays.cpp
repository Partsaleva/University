#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{

//
//Exercise 3.31: Write a program to define an array of ten ints. Give each
//element the same value as its position in the array.

	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i]=i;
		//cout<<arr[i]<<' ';
	}
	cout<<endl;

//Exercise 3.32: Copy the array you defined in the previous exercise into
//another array. 

	int arr2[10];
	for (int i = 0; i < 10; i++)
	{
		arr2[i]=arr[i];
		//cout<<arr2[i]<<' ';
	}

//Exercise 3.35: Using pointers, write a program to set the elements in an
//array to zero.

	int *p=arr2;
	for (int i = 0; i < 10; i++)
	{
		arr2[i]=*p;
		cout<<arr2[i]<<' ';
	}

//Exercise 3.36: Write a program to compare two arrays for equality. 

	int arr1[]={1,5,3};
	int arr2[]={1,2,3};
	int size1=sizeof(arr1)/sizeof(int);
	int size2=sizeof(arr2)/sizeof(int);
	if (size1==size2)
	{
		for (int i = 0; i < size1; i++)
		{
			if (arr1[i]==arr2[i])
			{
				cout<<"diff"<<endl;
				break;
			} 
		}
		
	}
	else
	{
		cout<<"diff"<<endl;
	}



	return 0;
}
