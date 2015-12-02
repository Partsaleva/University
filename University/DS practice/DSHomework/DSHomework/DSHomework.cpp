// DSHomework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include <string>

bool isCloseBracket(char br){
	return br == ')';
}

void decompress(std::string str){
	Stack<int> numbers; int num = 1;
	std::string temp = "", result = "";
	for (size_t i = 0; i <str.size(); i++)
	{
		//if letter save in temp string
		if (isalpha(str[i])){
			temp += str[i];
		}
		//if digit push into stack
		else if (isdigit(str[i])){
			int n=str[i] - '0';
			//if number -> make num
			while(isdigit(str[i+1])){
				n *= 10 + str[i + 1] - '0';
				i++;
			}
			numbers.push(n);
		}
		//if close bracket 
		else if (isCloseBracket(str[i])){
				num = numbers.pop(); //pop returns value
			//save temp string num-times in result
			for (int i = 0; i < num; i++)
			{
				if (temp.empty()){
					temp = result;
					result.clear();
				}
				result += temp;
			}

			temp.clear();
		}
	}
	result += temp;//if there is no brackets
	cout << result << endl;
}




int main()
{

	decompress("AB");

	decompress("3(A)");

	decompress("12(AB)");

	decompress("2(2(A)3(B))");

	decompress("4(A)4(B)");

	return 0;
}