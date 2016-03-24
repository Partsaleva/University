// TrainStation1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Cities.h"
#include "Trains.h"
#include "Schedule.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
void writeInFile(char* fileName, vector<T>& listToSave);
template <class T>
void PrintList(vector<T>& listToPrint);
void printMenu();


int main()
{
	vector<Cities> citiesList;
	vector<Trains> trainsList;
	vector<Schedule> schedulesList;	
	Cities city;
	Trains train;
	Schedule schedule;
	ifstream inputFile;
	inputFile.open("cities.txt", ios::in);      
	city.ReadCity(inputFile, citiesList);
	inputFile.close();

	inputFile.open("trains.txt", ios::in);      
	train.ReadTrains(inputFile, trainsList);
	inputFile.close();

	inputFile.open("schedules.txt", ios::in);      
	schedule.ReadSchedule(inputFile, schedulesList);
	inputFile.close();
	int choice;
	do{
	
	printMenu();
	
	cin >> choice;		
	switch(choice) {
		case 1:{
            Cities itemToAdd;				
			cout << "Enter Cities name: ";
			cin >> itemToAdd;
			bool isFound = city.ValidateCity(citiesList, itemToAdd);
			if (isFound)
			{
				citiesList.push_back(itemToAdd);
				writeInFile("cities.txt", citiesList);
			}
			else
			{cout << "Item already exists" << endl;}}
			 break;

        case 2:{
			Trains itemToAdd;				
			cout << "Enter Trains id, number of seats, description : ";
			cin >> itemToAdd;
			bool isFound = train.ValidateTrain(trainsList, itemToAdd);
			if (isFound)
			{
				trainsList.push_back(itemToAdd);
				writeInFile("trains.txt", trainsList);
			}
			else{cout << "Item already exists" << endl;}}
			   break; 

        case 3:{
			Schedule itemToAdd;
			cout << "Enter Schedule Start town, End town, date on leaving, time of leaving, name of train, ticket price: ";
			cin >> itemToAdd;
			bool isFound = schedule.ValidateSchedule(schedulesList, itemToAdd);
			if (isFound)
			{
				schedulesList.push_back(itemToAdd);
				writeInFile("schedules.txt", schedulesList);
			}
			else{
				cout << "Item already exists" << endl;}}
        break;

        case 4:{
			string trainID;
			cout << "Added cities by now: " << endl;
			PrintList(citiesList);
			cout << "Enter Cities name to remove: ";
			cin >> trainID;				
			city.RemoveCity(citiesList,trainID);}
        break;

		 case 5:{
			string trainID;
			cout << "Added trains by now: " << endl;
			PrintList(trainsList);
			cout << "Enter Trains name to remove: ";
			cin >> trainID;
			train.RemoveTrain(trainsList,trainID);}
			 break;

		 case 6:{
			string date;
			string hour;
			string trainID;
			cout << "All schedules by now: " << endl;
			PrintList(schedulesList);
			cout << "Enter Schedule date on leaving, time of leaving, name of train to remove: ";
			cin >> date >> hour >> trainID;			
			schedule.RemoveSchedule(schedulesList,date,hour,trainID);}
			 break;

		 case 7:{
			string trainID;
			cout << "Added trains by now: " << endl;
			PrintList(trainsList);
			cout << "Enter the name of the train you want to edit: ";
			cin >> trainID;
			train.EditTrain(trainsList, trainID);
			writeInFile("trains.txt", trainsList);}
			 break;

		 case 8:{
			string date;
			string hour;
			string trainID;
			cout << "All schedules by now: " << endl;
			PrintList(schedulesList);
			cout << "Enter Schedule date on leaving, time of leaving, name of train to edit: ";
			cin >> date >> hour >> trainID;
			schedule.EditSchedule(schedulesList, date, hour, trainID);
			writeInFile("schedules.txt", schedulesList);}
			 break;

		 case 9:
			 PrintList(citiesList);
			 break;

		 case 10:
			 PrintList(trainsList);
			 break;

		 case 11:
			 PrintList(schedulesList);
			 break;

		 case 12:{
			string from;
			string to;
			cout << "Enter Cities From - To: ";
			cin >> from >> to;
			cout << "Trains from " << from << " -> " << to <<endl;
			schedule.GetAllSchedulesFromTo(schedulesList, from, to);}
			 break;
    default:
        cout<< "Your selection must be between 1 and 13!\n";
		}
	}while (choice!=13);
	
}

void printMenu(){
	cout<<endl;
	cout << "Enter option from the following:"<<endl;
	cout <<"'1' - Add Cities"<<endl;
	cout <<"'2' - Add Trains"<<endl;
	cout <<"'3' - Add Schedule"<<endl;
	cout <<"'4' - Remove Cities"<<endl;
	cout <<"'5' - Remove Trains"<<endl;
	cout <<"'6' - Remove Schedule"<<endl;
	cout <<"'7' - Edit Trains"<<endl;
	cout <<"'8' - Edit Schedule"<<endl;
	cout <<"'9' - Print Cities List"<<endl;
	cout <<"'10' - Print Trains List"<<endl;
	cout <<"'11' - Print Schedule List"<<endl;
	cout <<"'12' - Get All Schedules From ... To ..."<<endl;
	cout <<"'13' - End"<<endl;
	cout<<endl;
}
template <class T>
void PrintList(vector<T>& listToPrint)
{
    if (listToPrint.size() == 0)
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        for (size_t index = 0; index < listToPrint.size(); index++)
        {
            cout << listToPrint[index];
        }
 
        cout << endl;
    }
}

template <class T>
void writeInFile(char* fileName, vector<T>& listToSave)
{
    std::ofstream file(fileName); 
    if(file.is_open())
    {
		for (size_t index = 0; index < listToSave.size(); index++)
		{
			file << listToSave[index];
		}
    }

    file.close(); 
}
