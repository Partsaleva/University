// BigCpp.cpp : Defines the entry point for the console application.
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



//Exercise 3.17: Read a sequence of words from cin and store the values a
//vector. After you’ve read all the words, process the vector and change
//each word to uppercase. Print the transformed elements, eight words to a
//line.

	vector<std::string> str;
	std::string word;
	while (cin>>word)
	{
		for (auto &w : word)
		{
			w=toupper(w);
		}
		str.push_back(word);
	}
	
	for (auto word : str)
	{
		cout<<word<<" ";
	}



//Exercise 3.20: Read a set of integers into a vector. Print the sum of each
//pair of adjacent elements. 


	vector<int> numbers;
	int sum=0;
	int n;
	while (cin>>n)
	{
		numbers.push_back(n);
	}
	for (decltype(numbers.size()) i = 0; i != numbers.size(); i=i+2)
	{
		sum=numbers[i]+numbers[i+1];
		cout<<sum<<' ';;
	}
//Change your program so that it prints the sum of
//the first and last elements, followed by the sum of the second and second-tolast,
//and so on.



	vector<int> num;
	int k, sums=0;
	while (cin>>k)
	{
		num.push_back(k);
	}
	for (decltype(num.size()) i = 0; i != num.size()/2; i++)
	{		
		sums=num[i]+num[num.size()-i-1];
		cout<<sums<<' ';;
	}
	
    

	return 0;
}

