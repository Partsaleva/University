#ifndef MAZE_H_
#define MAZE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Point{
	size_t row;
	size_t col;
	Point() :row(row), col(col){}
	~Point(){}
};

class Maze
{
public:
	Maze();
	~Maze();
	string readMaze(std::istream& file);
	void printMaze()const;
	void findWholePath(std::istream& file);
private:
	vector<string> matrix;
	//string points;
	string path, shortestPath;
	Point GivePosition(const char& letter);
	void printPath(string pathP)const;
	void findPath(const size_t& startRow, const size_t& startCol, const size_t& endRow,
		const size_t& endCol, const char& allow, const char& direction);
};

#endif

