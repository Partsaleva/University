#include "stdafx.h"
#include "Maze.h"


Maze::Maze(){}
Maze::~Maze(){}


string Maze::readMaze(std::istream& file){
	string line;
	size_t blank = INT_MAX;
	string points;
	points += 'S';
	for (size_t i = 0; getline(file, line); ++i)
	{
		if (line.empty()){

			blank = i;
		}
		else if (i < blank){

			matrix.push_back(line);
		}
		else// (i>blank)
		{
			points += line[1];
			points += line[0];
		}
	}
	points += 'X';
	return points;
}

void Maze::findWholePath(std::istream& file)
{
	string wholePath;
	string points = readMaze(file);
	printMaze();
	
	for (size_t i = 0; i < points.size(); i++)
	{
		if (points[i] == 'X')
		{
			break;
		}
		Point start = GivePosition(points[i]);
		Point end = GivePosition(points[i + 1]);
		path.clear();
		shortestPath.clear();

		findPath(start.row, start.col, end.row, end.col, points[i], ' ');
		path = shortestPath;

		for (size_t i = 0; i < path.size(); i++)
		{
			wholePath += path[i];
		}
	}
	printPath(wholePath);
	
}

Point Maze::GivePosition(const char &letter)
{
	Point position;
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		for (size_t j = 0; j < matrix[i].size(); ++j)
		{
			if (matrix[i][j] == letter)
			{
				position.row = i;
				position.col = j;
			}
		}
	}
	return position;
}

void Maze::findPath(const size_t& startRow, const size_t& startCol, const size_t& endRow, const size_t& endCol,
	const char& allow, const char& direction)
{
	if (startRow<0 || startCol<0 || startRow>matrix.size() - 1 || startCol> matrix[0].size() - 1)
	{
		return;
	}
	if (direction != ' ')
	{
		path.push_back(direction);
	}
	if (matrix[startRow][startCol] == matrix[endRow][endCol])
	{
		if (!path.empty())
		{
			if (!shortestPath.empty())
			{
				if (path.size() < shortestPath.size())
				{
					shortestPath = path;
				}
			}
			else
			{
				shortestPath = path;
			}
		}
	}
	if ((matrix[startRow][startCol] == ' ') || (matrix[startRow][startCol] == allow))
	{
		matrix[startRow][startCol] = '+';
		if (direction != 'R'){
			findPath(startRow, startCol - 1, endRow, endCol, allow, 'L');
		}
		if (direction != 'D'){
			findPath(startRow - 1, startCol, endRow, endCol, allow, 'U');
		}
		if (direction != 'L'){
			findPath(startRow, startCol + 1, endRow, endCol, allow, 'R');
		}
		if (direction != 'U'){
			findPath(startRow + 1, startCol, endRow, endCol, allow, 'D');
		}
		matrix[startRow][startCol] = ' ';
	}
	if (direction != ' ')
	{
		path.pop_back();
	}
}

void Maze::printPath(string pathP)const
{
	for (size_t i = 0; i < pathP.size(); ++i)
	{
		cout << pathP[i];
	}
	cout << endl;
}

void Maze::printMaze()const{
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		cout << matrix[i] << endl;
	}
	cout << endl;
}