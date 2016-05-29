// CppPrimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	//Exercises Section 5.4.1
		/*Exercise 5.14: Write a program to read strings from standard input
		looking for duplicated words.The program should find places in the input
		where one word is followed immediately by itself.Keep track of the largest
		number of times a single repetition occurs and which word is repeated.Print
		the maximum number of duplicates, or else print a message saying that no
		word was repeated.For example, if the input is
		how now now now brown cow cow
		the output should indicate that the word now occurred three times.*/
		
	
	string word , oldWord, newWord,result ;
	size_t count = 1,maxCount=0; 

	while (cin >> word)
	{		
		newWord = word;
		if (oldWord==newWord)
		{
			count++;
			if (count>maxCount)
			{
				maxCount = count;
				result = oldWord;
			}
		
		}
		else
		{
			count = 1;
		}
		oldWord = newWord;
	}
	
	cout <<result<<" "<<maxCount<<endl;
	
	
	return 0;
}


