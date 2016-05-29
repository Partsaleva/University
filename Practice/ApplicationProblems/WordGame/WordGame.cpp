// WordGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


std::vector <std::string> matrix;
						//x--,y++ , x--,y , x--,y-- , x,y++ , x,y--,  x++,y++, x++,y, x++,y--  
std::vector <int> directions = { -1, 1, -1, 0, -1, -1, 0, 1, 0, -1, 1, 1, 1, 0, 1, -1 };
std::string line;
std::string word = "ivan";

bool inBounderies(size_t row,size_t col){
	if (row>matrix.size()-1||col>matrix[0].size()-1)
	{
		return false;
	}
	else{
		return true;
	}
}

bool searchWord(int fRow, int fCol, int secRow, int secCol){
	size_t index = 0; 
	size_t size = word.size();
	while (inBounderies(fRow, fCol) && index <= size && (word[index] == matrix[fRow][fCol])){
		index++; 
		fRow += secRow;
		fCol += secCol;
		if (index==size){
			return true;
		}
	}
	return false;
}

void countWords(){
	size_t count = 0;
	
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j <matrix[i].size(); j++)
		{
			std::cout << matrix[i][j] << ' ';
			
			if (matrix[i][j]==word[0])
			{
				for (size_t k = 0; k < directions.size()-1 ; k+=2)
				{
					//{ -1, 1 , -1, 0 ,  -1, -1 ,  0, 1 ,  0,-1 ,  1, 1 ,  1, 0 ,  1,-1 };
					 
					int a = directions[k];
					int b = directions[k + 1];
					if (searchWord(i, j, a, b)){
						count++;
					}
				}
			}				
		}
		std::cout << std::endl;
			
	}
	std::cout << std::endl;
	std::cout << count << std::endl;
}


int main()
{
	
	std::ifstream file("words.txt");
	while (getline(file, line))
	{
		matrix.push_back(line);
	}
	
	countWords();

	return 0;
}

