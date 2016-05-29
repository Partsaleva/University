// CppPrimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	//Exercises Section 5.5.1
		/*Exercise 5.20: Write a program to read a sequence of strings from the
		standard input until either the same word occurs twice in succession or all
		the words have been read.Use a while loop to read the text one word at a
		time.Print the word if it occurs twice in succession, or else print a
		message saying that no word was repeated.*/

	string word;
	vector<string> str = {"aaaaa", "bbbb", "ccccc"};
	size_t max = str.size();
	size_t count = 0;
	/*while (cin >> word && !word.empty()){	
		str.push_back(word);
	}*/
	for (auto i = str.begin(); i != str.end()-1; i++)
	{
		for (auto j = i+1; j != str.end(); j++)
		{
			count++;
			if(*i==*j)
			{
				cout << "repeated word: " << *i << '\n';
				return 0;
			}
		}
		if (count == max)
		{
			cout << "no word was repeated" << endl;
			break;
		}
	}
	
	return 0;
}


