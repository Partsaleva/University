// Chapter7.1.2.1.cpp : Defines the entry point for the console application.
//
//Exercises Section 7.1.2
//Exercise 7.2: Add the combine and isbn members to the Sales_data
//class you wrote for the exercises in § 2.6.2 (p. 76).
//Exercise 7.3 : Revise your transaction - processing program from § 7.1.1 (p.
//256) to use these members.
#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;

struct Sales_data{
	string isbn;
	size_t unitsSold = 0;
	double revenue = 0.0;
	Sales_data(string isbn, size_t unitsSold, double revenue):isbn(isbn),unitsSold(unitsSold),revenue(revenue){}
	//string ISBN(){ return isbn; }
	Sales_data& combine(const Sales_data &rhs){
		unitsSold += rhs.unitsSold;
		revenue += rhs.revenue;
		return *this;
	}
};


int main()
{
	Sales_data total("123",3,6.50);
	Sales_data trans("123", 4,7.3);
	if (total.isbn==trans.isbn)
	{
		total.combine(trans);
	}
	else{
		cout << total.revenue << endl;
		total = trans;
	}
	cout << total.isbn << " " << total.unitsSold << " " << total.revenue << endl;
	return 0;
}

