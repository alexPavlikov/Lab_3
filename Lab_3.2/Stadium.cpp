#include "Stadium.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

Stadium::Stadium() {}
Stadium::Stadium(string nameStadium, string address, string nameDirector, string PlayingTeam, string ViewOfSport, bool OlympicReserve, double AverageAttendance, double Rating,
	int YearOfCreation, int Size, int Worker, int ValueSectors)
{
	this->nameStadium = nameStadium;
	this->address = address;
	this->nameDirector = nameDirector;
	this->PlayingTeam = PlayingTeam;
	this->ViewOfSport = ViewOfSport;
	this->OlympicReserve = OlympicReserve;
	this->AverageAttendance = AverageAttendance;
	this->Rating = Rating;
	this->YearOfCreation = YearOfCreation;
	this->Size = Size;
	this->Worker = Worker;
	this->ValueSectors = ValueSectors;

}

void Stadium::setName(string name) {
	this->nameStadium = nameStadium;
}
void Stadium::setAddress(string address)
{
	this->address = address;
}

void Stadium::setDirector(string nameDirector)
{
	this->nameDirector = nameDirector;
}
void Stadium::setTeam(string PlayingTeam)
{
	this->PlayingTeam = PlayingTeam;
}

void Stadium::setViewOfSport(string setViewOfSport)
{
	this->ViewOfSport = ViewOfSport;
}

void Stadium::setReserve(bool OlympicReserve)
{
	this->OlympicReserve = OlympicReserve;
}
void Stadium::setAverageAttendance(double AverageAttendance)
{
	this->AverageAttendance = AverageAttendance;
}
void Stadium::setRating(double Rating)
{
	this->Rating = Rating;
}
void Stadium::setYearOfCreation(int YearOfCreation)
{
	this->YearOfCreation = YearOfCreation;
}
void Stadium::setSize(int Size)
{
	this->Size = Size;
}
void Stadium::setWorker(int Worker)
{
	this->Worker = Worker;
}
void Stadium::setValueSector(int ValueSector)
{
	this->ValueSectors = ValueSectors;
}


//------------------------------------------------------------------------------

void Stadium::serialize() {
	ofstream fout;
	fout.open("Stadium.txt", ofstream::app);

	if (fout.is_open()) {
		printf("\nFile is open");
		fout.write((char*)this, sizeof(Stadium));
	}
	else {
		printf("\nError opening file");
	}

	fout.close();
}

void Stadium::deserialize() {
	ifstream fin;
	fin.open("Stadium.txt");

	if (fin.is_open()) {
		printf("\nFile is open");

	}
	else {
		printf("\nError opening file");
		fin.read((char*)this, sizeof(Stadium));

	}

	fin.close();
}

void Stadium::serialize(const string& file) const {
	ofstream fout;
	fout.open(file, ofstream::app);

	if (fout.is_open()) {
		printf("\nFile is open");
		fout.write((char*)this, sizeof(Stadium));
	}
	else {
		printf("\nError opening file");
	}

	fout.close();
}

void Stadium::deserialize(const string& file) {
	ifstream fin;
	fin.open(file);

	if (fin.is_open()) {
		printf("\nFile is open");

	}
	else {
		printf("\nError opening file");
		fin.read((char*)this, sizeof(Stadium));
	}

	fin.close();
}

Stadium::~Stadium() {}


