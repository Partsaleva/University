// CppPrimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

int fact(int number){	
	if (number > 1)
		return fact(number - 1) * number;
	return 1;

}

void fact(){
	int number,fact=1;
	cout << "Number: ";
	cin >> number;
	while (number>1)
	{
		fact *= number;
		number--;
	}
	cout << "factorial: " << fact << endl;
}

int absVal(int val){
	return abs(val);
}

int call(){	
	static int count = 0;
	return count++;
}
int main()
{
	//Exercises Section 6.1
		/*Exercise 6.3: Write and test your own version of fact.*/
		/*Exercise 6.4 : Write a function that interacts with the user, asking for a
		number and generating the factorial of that number.Call this function from
		main.*/
		/*Exercise 6.5 : Write a function to return the absolute value of its argument.*/

	//Exercises Section 6.1.1
		//Exercise 6.7: Write a function that returns 0 when it is first called and then
		//generates numbers in sequence each time it is called again.

	cout << fact(5) << endl;
	fact();
	cout << absVal(-5) << endl;
	cout << call() << endl;
	cout << call() << endl;
	cout << call() << endl;
	cout << call() << endl;
	cout << call() << endl;
	
	return 0;
}


