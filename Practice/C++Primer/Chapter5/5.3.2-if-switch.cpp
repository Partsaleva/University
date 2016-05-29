// CppPrimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
	//Exercises Section 5.3.2

	/*Exercise 5.9: Write a program using a series of if statements to count the
	number of vowels in text read from cin.*/

	char ch; int cnt = 0;
	while (cin>>ch)
	{
		if (ch=='a')
			++cnt;
		if (ch == 'e')
			++cnt;
		if (ch == 'i')
			++cnt;
		if (ch == 'o')
			++cnt;
		if (ch == 'u')
			++cnt;	
	}
	cout << cnt << endl;

	/*Exercise 5.10 : There is one problem with our vowel - counting program as
	we’ve implemented it : It doesn’t count capital letters as vowels.Write a
	program that counts both lower - and uppercase letters as the appropriate
	vowel—that is, your program should count both 'a' and 'A' as part of
	aCnt, and so forth.*/

	char ch; int cnt = 0;
	while (cin >> ch)
	{
		if (ch == 'a' || ch=='A')
			++cnt;
		if (ch == 'e' || ch == 'E')
			++cnt;
		if (ch == 'i' || ch == 'I')
			++cnt;
		if (ch == 'o' || ch == 'O')
			++cnt;
		if (ch == 'u' || ch == 'U')
			++cnt;
	}
	cout << cnt << endl;

	char ch; int cnt = 0;
	while (cin>>ch)
	{
		switch (ch)
		{
		case 'a': case 'e': case 'i': case 'o': case 'u':
		case 'A': case 'E': case 'I': case 'O': case 'U':
			++cnt;
			break;
		default:
			break;
		}
	}
	cout << cnt << endl;

	/*Exercise 5.11 : Modify our vowel - counting program so that it also counts the
	number of blank spaces, tabs, and newlines read.*/

	string str; int cnt = 0;
	getline(cin,str);
	for (char ch : str){
		if (ch == 'a' || ch == 'A' ||
			ch == 'e' || ch == 'E' ||
			ch == 'i' || ch == 'I' || 
			ch == 'o' || ch == 'O'||
			ch == 'u' || ch == 'U' || 
			isspace(ch)){
			cnt++;
		}
	}

	cout << cnt << endl;


	
	return 0;
}


