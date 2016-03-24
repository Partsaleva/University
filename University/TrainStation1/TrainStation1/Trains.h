#ifndef TRAINS_H
#define TRAINS_H
#include "Schedule.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Trains
{
private:
	string trainID;
	size_t places;
	string description;

public:
	Trains();
	Trains(string trainID, int places, string description);
	~Trains();
	
	string trim(string& str);
	friend ostream& operator<<(ostream& out, const Trains& t);
	friend istream& operator>>(istream& in,Trains& t);

	//Checks if there is a train with the same ID
	bool ValidateTrain(vector<Trains> trains, Trains train);

	//edit 
	void EditTrain(vector<Trains>& trains, string trainId);

	//remove train
	void RemoveTrain(vector<Trains>& trains, string trainId);

	//prints file
	void ReadTrains(ifstream& inputFile, vector<Trains>& trains);
	
};

#endif