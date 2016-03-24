#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Schedule
{
private:
	int number;
	string fromStation;
	string toStation;
	string dateOfTravel;
	string timeOfTravel;
	string trID;
	double priceOfTicket;
public:	
	Schedule();
	Schedule(string fromStation, string toStation, string dateOfTravel, string timeOfTravel, string trID, double priceOfTicket);
	~Schedule();
	string trim(string& str);

	friend ostream& operator<<(ostream& out, const Schedule& s);
	friend istream& operator>>(istream& in,Schedule& s);

	bool ValidateSchedule(vector<Schedule> schedules, Schedule schedule);

	void GetAllSchedulesFromTo(vector<Schedule>& schedules, string from, string to);

	void EditSchedule(vector<Schedule>& schedules, string date, string hour, string trainId);

	void RemoveSchedule(vector<Schedule>& schedules, string date, string hour, string trainId);

	void ReadSchedule(ifstream& inputFile, vector<Schedule>& schedules);

	
};

#endif