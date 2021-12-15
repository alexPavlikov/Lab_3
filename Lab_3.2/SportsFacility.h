#pragma once
#include <string>
#include <vector>

using namespace std;

class SportsFacility
{

protected:
	string address_;
	string TypeOfCoverage_;
	int capacity_;
	int SeasonTickets_;
	float square_;
	float attendance_;
	float AvgAttendance_;
	vector <float> HistoryOfAttendances_;

public:
	virtual ~SportsFacility(){}
	void setAddress(string address);
	void setTypeOfCoverage(string type_of_coverage);
	void setCapacity(int capacity);
	virtual void setSeasonTickets(int season_tickets);
	void setSquare(float square);
	void setAttendance(float Attendance);
	void playGame(int visitors);
	float calculateAttendance(int visitors) const;
	friend ostream& operator<<(ostream& out, const SportsFacility& s);
};
