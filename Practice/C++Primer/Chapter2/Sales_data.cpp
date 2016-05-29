// BigCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

struct Sales_data{
	std::string bookNo;
	unsigned unitsSold;
	double revenue;
};
int main()
{
	Sales_data book1,book2;
	int price=0;
	double totalCount;
	int totalRevenue;
	std::cin>>book1.bookNo>>book1.unitsSold>>price;
	book1.revenue=book1.unitsSold*price;

    std::cin>>book2.bookNo>>book2.unitsSold>>price;
	book2.revenue=book2.unitsSold*price;

	if (book1.bookNo==book2.bookNo)
	{
		totalCount=book1.unitsSold+book2.unitsSold;
		totalRevenue=book1.revenue+book2.revenue;

		std::cout<<book1.bookNo<<": copies: "<<totalCount<<", sum: "<<totalRevenue<<std::endl;
		if (totalCount!=0)
		{
			std::cout<<"average sum: "<<totalRevenue/totalCount<<std::endl;
		}else
		{
			std::cout<<"no sales"<<std::endl;
		}
		return 0;
	}
	else
	{
		std::cerr<<"Data must refer to the same ISBN"<<std::endl;
		return -1;
	}
	
	return 0;
}

