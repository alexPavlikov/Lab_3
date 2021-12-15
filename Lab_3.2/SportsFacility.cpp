#include "SportsFacility.h"
#include <iostream>

using namespace std;

void SportsFacility::setAddress(string address) {
	address_ = address;
}

void SportsFacility::setTypeOfCoverage(string TypeOfCoverage){
	TypeOfCoverage_ = TypeOfCoverage;
}

void SportsFacility::setCapacity(int capacity) {
	capacity_ = capacity;
}

void SportsFacility::setSeasonTickets(int SeasonTickets){
	SeasonTickets_ = SeasonTickets;
}

void SportsFacility::setSquare(float square){
	square_ = square;
}

void SportsFacility::setAttendance(float attendance) {
	attendance_ = attendance;
}

void SportsFacility::playGame(int visitors) {
	HistoryOfAttendances_.push_back(calculateAttendance(visitors));
	float sum = 0;
	for (size_t i = 0; i < HistoryOfAttendances_.size(); ++i)
	{
		sum += HistoryOfAttendances_[i];
	}
	AvgAttendance_ = sum / HistoryOfAttendances_.size();
}

float SportsFacility::calculateAttendance(int visitors)const {
	return (float)visitors / capacity_ * 100;
}

ostream& operator<<(ostream& out, const SportsFacility& s) {
	out << "The sport facility is in " << s.address_ << endl;
	out << "Capacity: " << s.capacity_ << endl;
	out << "Number of available season tickets: " << s.SeasonTickets_ << endl;

	return out;
}