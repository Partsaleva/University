#include "stdafx.h"
#include "Schedule.h"

Schedule::Schedule(){}
Schedule::~Schedule(){}
Schedule::Schedule(string fromStation, string toStation, string dateOfTravel, 
				   string timeOfTravel, string trID, double priceOfTicket):

	fromStation(fromStation), toStation(toStation),
	dateOfTravel(dateOfTravel), timeOfTravel(timeOfTravel),
	trID(trID),priceOfTicket(priceOfTicket){}

string Schedule::trim(string& str){
		str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
		str.erase(str.find_last_not_of(' ')+1);         //surfixing spaces
		return str;
}
ostream& operator<<(ostream& out, const Schedule& s){
	out<<s.number<<'.'<<s.fromStation<<"->"<<s.toStation<<","
	   <<s.dateOfTravel<<","<<s.timeOfTravel
	   <<","<<s.trID<<","<<s.priceOfTicket<<endl;
		return out;
}

istream& operator>>(istream& in,Schedule& s){
	    in>>s.number;
	    getline(in,s.fromStation);
		getline(in,s.toStation);
		in >>s.dateOfTravel>>s.timeOfTravel
			>>s.trID>>s.priceOfTicket;     
        return in;
}


bool Schedule::ValidateSchedule(vector<Schedule> schedules, Schedule schedule)
{
	for (size_t i = 0; i != schedules.size(); i++)
	{
		if (schedules[i].fromStation == schedule.fromStation && schedules[i].toStation == schedule.toStation
			&& schedules[i].dateOfTravel == schedule.dateOfTravel && schedules[i].timeOfTravel == schedule.timeOfTravel
			&& schedules[i].trID == schedule.trID)
		{
			return false;
		}
	} 
	
	return true;
}

 void Schedule::GetAllSchedulesFromTo(vector<Schedule>& schedules, string from, string to)
{
    bool isFound = false;
 
    for (size_t i = 0; i != schedules.size(); i++)
    {
        if (schedules[i].fromStation.compare(from) == 0
            && schedules[i].toStation.compare(to) == 0)
        {
            isFound = true;
            cout << schedules[i] << endl;
        }
    }
 
    if (!isFound)
    {
        cout << "No trains from " << from << " to " << to << " found!" << endl;
    }
}

 void Schedule::EditSchedule(vector<Schedule>& schedules, string date, string hour, string trainId)
{
    int pos = 0;
    bool isFound = false;
 
    for (size_t i = 0; i != schedules.size(); i++)
    {
        if (schedules[i].dateOfTravel.compare(date) == 0
            && schedules[i].timeOfTravel.compare(hour) == 0
            && schedules[i].trID.compare(trainId) == 0)
        {
            isFound = true;
            pos = i;
        }
    }
 
    if (isFound)
    {
        schedules.erase(schedules.begin() + pos);
 
        Schedule sched;
		cout << "Enter new train characteristics: "<<endl;
        cin >> sched;
 
        schedules.insert(schedules.begin() + pos, sched);
    }
    else
    {
        cout << "The schedule was not found in the list" << endl;
    }
}

 void Schedule::RemoveSchedule(vector<Schedule>& schedules, string date, string hour, string trainId)
{
    int pos = 0;
    bool isFound = false;
 
    for (size_t i = 0; i != schedules.size(); i++)
    {
        if (schedules[i].dateOfTravel.compare(date) == 0
            && schedules[i].timeOfTravel.compare(hour) == 0
            && schedules[i].trID.compare(trainId) == 0)
        {
            isFound = true;
            pos = i;
        } 
    }
 
    if (isFound)
    {
        schedules.erase(schedules.begin() + pos);
    }
	else
	{
		cout << "Schedule not found" << endl;
	}
}

 void Schedule::ReadSchedule(ifstream& inputFile, vector<Schedule>& schedules)
{
        while (!inputFile.eof())
        {
                Schedule sched;
                string fromTo;
				inputFile>>sched.number;
                getline(inputFile, fromTo, ',');
 
                size_t arrowIndex = fromTo.find_first_of('>');
                string townFrom = fromTo.substr(0, arrowIndex - 1);
                string townTo = fromTo.substr(arrowIndex + 1);
                sched.fromStation = trim(townFrom);
                sched.toStation = trim(townTo);
 
                getline(inputFile, sched.dateOfTravel, ',');
                sched.dateOfTravel = trim(sched.dateOfTravel);
 
                getline(inputFile, sched.timeOfTravel, ',');
                sched.timeOfTravel = trim(sched.timeOfTravel);
 
                getline(inputFile, sched.trID, ',');
                sched.trID = trim(sched.trID);
 
				inputFile >> sched.priceOfTicket;
 
                schedules.push_back(sched);
        }
}