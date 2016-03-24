#include "stdafx.h"
#include "Cities.h"

Cities::Cities(){}
Cities::~Cities(){}
Cities::Cities(string cityName):cityName(cityName){}


ostream& operator<<(ostream& out, Cities& city)
{

	out<<city.cityName << endl;
	
	return out;
}
 
istream& operator>>(istream& in, Cities& city)
{
	in >>city.cityName;
 
        return in;
}

bool Cities::ValidateCity(vector<Cities> cities, Cities city)
{
	for (size_t i = 0; i != cities.size(); i++)
	{
		if (cities[i].cityName == city.cityName)
		{
			return false;
		}
	} 
	
	return true;
}

void Cities::RemoveCity(vector<Cities>& cities, string cityName)
{
        int position = 0;
        bool isFound = false;
 
        for (size_t i = 0; i != cities.size(); i++)
        {
            if (cities[i].cityName.compare(cityName) == 0)
        {
            isFound = true;
            position = i;
        }
		}

        if (isFound)
        {
                cities.erase(cities.begin() + position);
        }
		else
		{
			cout << "City not found" << endl;
		}
}

void Cities::ReadCity(ifstream& inputFile, vector<Cities>& cities)
{
	Cities city;
	while(inputFile >> city.cityName)
    {
		cities.push_back(city);
    }
}