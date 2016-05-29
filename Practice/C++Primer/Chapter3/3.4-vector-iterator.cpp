// CppPrimer.cpp : Defines the entry point for the console application.
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


	//Exercises Section 3.4...

	//Exercise 3.21: Redo the first exercise from § 3.3.3 (p. 105) using iterators.
	//: Read a sequence of words from cin and store the values a
	//vector. After you’ve read all the words, process the vector and change
	//each word to uppercase. Print the transformed elements, eight words to a
	//line.

	vector<std::string> str;
	std::string word;
	while (cin>>word)
	{
	word[0]=toupper(word[0]);
	str.push_back(word);
	}
	for (auto i = str.begin(); i != str.end(); i++)
	{
	cout<<*i<<" ";
	}


	//Exercise 3.22: Revise the loop that printed the first paragraph in text to
	//instead change the elements in text that correspond to the first paragraph
	//to all uppercase. After you’ve updated text, print its contents.

	vector<std::string> str;
	std::string word;
	while (cin>>word)
	{
	for (auto i = word.begin(); i != word.end(); i++)
	{
	*i=toupper(*i);
	}
	str.push_back(word);
	}
	for (auto i = str.begin(); i != str.end(); i++)
	{
	cout<<*i<<" ";
	}

	//Exercise 3.23: Write a program to create a vector with ten int elements.
	//Using an iterator, assign each element a value that is twice its current value.
	//Test your program by printing the vector.
	vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	for (auto i = numbers.begin(); i != numbers.end(); i++)
	{
		*i = (*i) * (*i);
	}	

	for (auto i = numbers.begin(); i != numbers.end(); i++)
	{
		cout << *i << " ";
	}


	return 0;
}


