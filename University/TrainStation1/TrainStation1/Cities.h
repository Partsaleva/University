#ifndef CITIES_H
#define CITIES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Cities
{
private:
	string cityName;
public:
	Cities();
	Cities(string cityName);
	~Cities(void);	

	friend ostream& operator<<(ostream& out, Cities& city);
	friend istream& operator>> (istream& in, Cities& city);

	//Checks if this city is not listed already
	bool ValidateCity(vector<Cities> cities, Cities city);

	//Removes city from file
	void RemoveCity(vector<Cities>& cities, string cityName);

	//prints file
	void ReadCity(ifstream& inputFile, vector<Cities>& cities);
};

#endif
