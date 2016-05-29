// CppPrimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


void swap(int* a, int *b){
	int* temp = a;
	a = b;
	b = temp;
	cout << *a << ' ' << *b << endl;
}

int reset(int &num){
	num = 0;
	return num;
}

void swapRef(int &a, int&b){
	int temp = a;
	a = b;
	b = temp;
	cout << a << ' ' << b << endl;
}

bool findUp(const string &str){
	for (auto let : str)
	{
		if (isupper(let))
		{
			return true;
		}
	}
	return false;
}
bool strFunc(const string &str){
	return findUp(str);
}

 string changeStr(string &str){
	for (auto &let : str){
		let=tolower(let);
	}
	return str;
}

 int compareIntAndPointer(const int &intNum, const int* pointer){
	 if (intNum>*pointer)
	 {
		 return intNum;
	 }
	 else{
		 return *pointer;
	 }
 }

 void swapPointers(int *a, int *b){
	 int *temp = a;
	 a = b;
	 b = temp;
	 cout << *a <<' '<< *b << endl;
 }

 void print(int(&arr)[2])
 {
	 for (auto elem : arr){
		 cout << elem << ' ';
	 }
 }
 void print2(const int *beg, const int *end)
 {
	 while (beg != end){
		 cout << *beg++ << endl;
	 }
 }

int main()
{/*
	Exercises Section 6.2.1
		Exercise 6.10: Using pointers, write a function to swap the values of two
		ints.Test the function by calling it and printing the swapped values.*/
	int a = 3, b = 5;
	swap(&a, &b);

	//Exercises Section 6.2.2
		//Exercise 6.11: Write and test your own version of reset that takes a reference.
	int c = 5;
	cout << reset(c)<< endl;

		//Exercise 6.12 : Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210)
		//to use references instead of pointers to swap the value of two ints.

	int d = 2, e = 10;
	swapRef(d, e);

	/*Exercise 6.17: Write a function to determine whether a string contains
	any capital letters.Write a function to change a string to all lowercase*/
	string str= "alA bAla Nica";
	cout<<strFunc(str)<<endl;
	cout<<changeStr(str)<<endl;

	//Exercises Section 6.2.4
		/*Exercise 6.21: Write a function that takes an int and a pointer to an int
		and returns the larger of the int value or the value to which the pointer
		points.What type should you use for the pointer ?*/
	int f = 5, g = 10; int* h = &g;
	cout << compareIntAndPointer(f, h) << endl;;

		//Exercise 6.22 : Write a function to swap two int pointers.
	int l = 5, m = 7;
	int* i=&l, *k=&m;
	swapPointers(i,k);

		/*Exercise 6.23 : Write your own versions of each of the print functions
		presented in this section.Call each of these functions to print i and j
		defined as follows :*/ 
		int n = 0, j[2] = { 0, 1 };
		print(j);


	return 0;
}


