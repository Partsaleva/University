// CppPrimerChapter7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
struct Sales_data{
	std::string bookNo;
	size_t unitsSold=0;
	double revenue=0.0;
};


int main()
{
	Sales_data total;
	if (cin>>total.bookNo>>total.unitsSold>>total.revenue){
		Sales_data trans;
		while (cin>>trans.bookNo>>trans.unitsSold>>trans.revenue)
		{
			if (total.bookNo==trans.bookNo)
			{
				total.revenue += trans.revenue;
				total.unitsSold+=trans.unitsSold;
			}
			else{
				cout << total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.unitsSold << " " << total.revenue << endl;

	}
	else
	{
		cerr << "No data" << endl;
		return -1;
	}

	return 0;
}

