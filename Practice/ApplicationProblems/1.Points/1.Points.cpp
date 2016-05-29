// 1.Points.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


void reset(){
	char right = '>', left = '<';
	char up = '^', down = 'v';
	char warp = '~';
}
void position(int x, int y, std::string instruction){
	char right = '>', left = '<';
	char up = '^', down = 'v';
	char warp = '~';

	for (size_t i = 0; i < instruction.size(); ++i)
	{
		if (instruction[i]==right){
			x++;
		}
		else if (instruction[i] == left){
			x--;
		}
		else if (instruction[i] == up){
			y--;
		}
		else if (instruction[i] == left){
			y++;
		}
		else {
			
			std::swap(right, left);
			std::swap(up, down);

		}
		
	}
	std::cout << x << ' ' << y << std::endl;
}

int main()
{
	std::string inp = ">>><<<~>>>~^^^";
	position(0, 0, inp);

	return 0;
}

