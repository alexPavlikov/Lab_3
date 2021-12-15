#define _CRT_SECURE_NO_WARNINGS
#include "Court.h"
#include <iostream>
#include <ctime>
  
using namespace std;

Court::Court() {
	address_ = "Barcelona";
	capacity_ = 10; 
	attendance_ = 7.5; 
	AvgAttendance_ = 7.5; 
	HistoryOfAttendances_.reserve(4);
	SeasonTickets_ = 15;
}
Court::Court(string address, int capacity, float attendance, string TypeOfCoverage) {
	address_ = address;
	capacity_ = capacity; //вместимость
	attendance_ = attendance; // посещаемость
	TypeOfCoverage_ = TypeOfCoverage; // тип покрытия
	AvgAttendance_ = 0.0; // средняя посещаемость
	HistoryOfAttendances_.reserve(4);
	SeasonTickets_ = 15;
}

void Court::setSeasonTickets(int SeasonTickets){
	SeasonTickets_ = SeasonTickets > 15 ? 15 : SeasonTickets;
}

void Court::ticket(){
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int currentMonth = 1 + ltm->tm_mon;
	if (currentMonth > 5 && currentMonth < 9) {
		if (SeasonTickets_ > 0) {
			SeasonTickets_--;
			cout << "Issued season ticket with number: " << 16 - SeasonTickets_ << endl;
		}
		else {
			cout << "No more season tickets" << endl;
		}
	}
	else {
		cout << "Now is not the time to buy season tickets" << endl;
	}
}

	ostream& operator<<(ostream& out, const Court& s) {
	out << "The court is in " << s.address_ << endl;
	out << "Capacity: " << s.capacity_ << endl;
	out << "Number of available season tickets: " << s.SeasonTickets_ << endl;

	return out;
}

