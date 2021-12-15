#pragma once
#include "Stadium.h"
#include <string>
#include <fstream>

using namespace std;

class Stadium
{
public:

	string nameStadium;
	string address;
	string nameDirector;
	string PlayingTeam;
	string ViewOfSport;
	bool OlympicReserve; // 1-YES, 0-NO
	double AverageAttendance;
	double Rating;
	int YearOfCreation;
	int Size;
	int Worker;
	int ValueSectors;

public:
	Stadium();
	Stadium(string nameStadium, string address, string nameDirector, string PlayingTeam, string ViewOfSport, bool OlympicReserve, double AverageAttendance, double Rating,
		int YearOfCreation, int Size, int Worker, int ValueSectors);

	void setName(string nameStadium);
	void setAddress(string address);
	void setDirector(string nameDirector);
	void setTeam(string PlayingTeam);
	void setViewOfSport(string ViewOfSport);
	void setReserve(bool OlympicReserve);
	void setAverageAttendance(double AverageAttendance);
	void setRating(double Rating);
	void setYearOfCreation(int YearOfCreation);
	void setSize(int Size);
	void setWorker(int Worker);
	void setValueSector(int ValueSector);
	void serialize();
	void deserialize();
	void serialize(const string& file) const;
	void deserialize(const string& file);

	~Stadium();
};



