#include "stdafx.h"
#include "Trains.h"


Trains::Trains(void){}
Trains::~Trains(void){}

Trains::Trains(string trainID, int places, string description):trainID(trainID),places(places),description(description){}

string Trains::trim(string& str){
		str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
		str.erase(str.find_last_not_of(' ')+1);         //surfixing spaces
		return str;
}

ostream& operator<<(ostream& out, const Trains& train){
	out << train.trainID <<","
		<<train.places << ","
	    <<train.description<< endl;
    
    return out;
}

istream& operator>>(istream& in,Trains& train){
	  
		in >> train.trainID ;
		in	>> train.places;
		getline(in, train.description);
		train.description = train.trim(train.description);
       
        return in;
}


bool Trains::ValidateTrain(vector<Trains> trains, Trains train)
{
	for (size_t i = 0; i != trains.size(); i++)
	{
		if (trains[i].trainID == train.trainID)
		{
			return false;
		}
	} 
	
	return true;
}

void Trains::EditTrain(vector<Trains>& trains, string trainId)
{
    int pos = 0;
    bool isFound = false;
 
    for (size_t i = 0; i != trains.size(); i++)
    {
        if (trains[i].trainID.compare(trainId) == 0)
        {
            isFound = true;
            pos = i;
        }
    }

    if (isFound)
    {
        trains.erase(trains.begin() + pos);
 
        Trains train;
		
		cout << "Enter new train characteristics: "<<endl;
        cin >> train;
		
        trains.insert(trains.begin() + pos, train);
 
    
    }
    else
    {
        cout << "The train was not found in the list" << endl;
    }
}

void Trains::RemoveTrain(vector<Trains>& trains, string trainId)
{
    int pos = 0;
    bool isFound = false;
 
    for (size_t i = 0; i != trains.size(); i++)
    {
        if (trains[i].trainID.compare(trainId) == 0)
        {
            isFound = true;
            pos = i;
        }
    }
 
    if (isFound)
    {
        trains.erase(trains.begin() + pos);
    }
	else 
	{
		cout << "Trains not found" << endl;
	}
}

void Trains::ReadTrains(ifstream& inputFile, vector<Trains>& trains)
{
	
	Trains train;
	inputFile >> train.trainID>>train.places;
	getline(inputFile,train.description);
	trains.push_back(train);
    
}


 
