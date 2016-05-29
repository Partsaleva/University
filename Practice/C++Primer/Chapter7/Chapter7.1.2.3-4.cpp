// Chapter7.1.2.3-4.cpp : Defines the entry point for the console application.
//
//Exercise 7.4: Write a class named Person that represents the name and
//address of a person.Use a string to hold each of these elements.

//Subsequent exercises will incrementally add features to this class.
//Exercise 7.5 : Provide operations in your Person class to return the name and address.
#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Person{
public:
	const string personName(){ return name; }
	const string personAddr(){ return address; }
private:
	string name;
	string address;
};
int main()
{
	return 0;
}

