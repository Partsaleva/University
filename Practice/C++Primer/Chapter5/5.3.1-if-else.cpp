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
using std::string;


int main()
{
	/*Exercises Section 5.3.1
	
		Exercise 5.5: Using an if–else statement, write your own version of the
		program to generate the letter grade from a numeric grade.*/
	vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	string letterGrade;
	int grade;
	while (cin >> grade)
	{
		
		if (grade < 60)
		{
			letterGrade = scores[0];

		}
		else
		{
			letterGrade = scores[(grade - 50) / 10];
			if (grade%10>=5)
			{
				letterGrade += '+';
			}
		}
		cout << letterGrade << endl;
	}

		/*Exercise 5.6 : Rewrite your grading program to use the conditional operator
		 in place of the if–else statement.*/
	string finalGrade;
	int grade;

	while (cin >> grade){
		finalGrade = (grade < 60) ? "F"
			: (grade < 70) ? "D"
			: (grade < 80) ? "C"
			: (grade < 90) ? "B"
			: (grade < 100) ? "A"
			: "A++";

		finalGrade = (grade % 10 >= 5&&grade>60) ? finalGrade += '+' : finalGrade;

		cout << finalGrade<<endl;
	}
	return 0;
}


