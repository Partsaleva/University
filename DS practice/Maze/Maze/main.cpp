#include "stdafx.h"
#include <iostream>

#include "Maze.h"
using std::ifstream;
using std::cin;
using std::cout;

int main(int argc, char* argv[])
{
	/*string  fileName;
	cout << "file name: ";
	cin >> fileName;
	ifstream file;
	file.open(fileName);

	if (file.fail())
	{
	cout << "Error opening " << fileName << "\n";
	return 1;
	}
*/
	Maze maze;
	ifstream file("maze.txt");
	//maze.readMaze(file);
	//maze.printMaze();
	maze.findWholePath(file);
	
	cout << endl;cout << endl;
	file.close();

}