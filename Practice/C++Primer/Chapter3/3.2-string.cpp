// BigCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{


	/*Exercise 3.2: Write a program to read the standard input a line at a time.
Modify your program to read a word at a time.*/

	std::string input;
	getline(cin,input);
	cout<<input<<endl;

	std::string word, s="";
	while (cin>>word)
	{
		cout<<word<<endl;
		
	}
	
	


////Exercise 3.4: Write a program to read two strings and report whether the
////strings are equal. If not, report which of the two is larger. Now, change
////the program to report whether the strings have the same length, and if
////not, report which is longer.

	std::string str1;
	std::string str2;

	cin>>str1>>str2;
	if (str1==str2)
	{
		cout<<"strings are equal"<<endl;
	}else
	{
		if (str1>str2)
		{
			cout<<str1<<" is larger"<<endl;
		}else
		{
			cout<<str2<<" is larger"<<endl;
		}
	}

	if (str1.size()==str2.size())
	{
		cout<<"strings are with same length"<<endl;
	}else
	{
		if (str1.size()>str2.size())
		{
			cout<<str1<<" is longer"<<endl;
		}else
		{
			cout<<str2<<" is longer"<<endl;
		}
	}


////Exercise 3.5: Write a program to read strings from the standard input,
////concatenating what is read into one large string. Print the concatenated
////string.Next, change the program to separate adjacent input strings by a space.

	std::string word, s="", s1="";
	while (cin)
	{
		s+=word;
		s1+=word+" ";
		cin>>word;
		
	}
	cout<<s<<endl;
	cout<<s1<<endl;



//Exercise 3.6: Use a range for to change all the characters in a string to X.

	std::string str("blabla bla bla lba abla");
	
	for (auto &c:str)
	{
		c='X';
	}
	cout<<str<<endl;*/



//Exercise 3.8: Rewrite the program in the first exercise, first using a while
//and again using a traditional for loop. Which of the three approaches do
//you prefer and why?

	char c; std::string str="";
	while (cin>>c)
	{
		str+='X';
	}
	cout<<str<<endl;

	for (int i = 0; i < str.size(); i++)
	{
		str[i]='X';
	}
	cout<<str<<endl;


//Exercise 3.10: Write a program that reads a string of characters including
//punctuation and writes what was read but with the punctuation removed.

	std::string str("blabla, bla, bla lba abla!!!");

	for (auto &c:str)
	{
		if (ispunct(c))
		{
			c=' ';
		}
	}
	cout<<str<<endl;



	return 0;
}

