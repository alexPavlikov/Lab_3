// Павликов А.О. ИВТ-4(уск) Вариант 7

#include "Stadium.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>

using namespace std;

 void printInfo(Stadium a, Stadium b, Stadium c)
{

	int const N = 3;
	Stadium mas[N] = { a,b,c };

	// string nameStadium, string address, string nameDirector, string PlayingTeam, string ViewOfSport, bool OlympicReserve, double AverageAttendance, double Rating, 
	// int YearOfCreation, int Size, int Worker, int ValueSectors

	for (int i = 0; i < N; i++) {
		cout << i + 1 << ") " << mas[i].nameStadium << "\n" << mas[i].address << "\n" << mas[i].nameDirector << "\n" << mas[i].PlayingTeam << "\n" << mas[i].ViewOfSport
			<< "\n" << mas[i].OlympicReserve << "\n" << mas[i].AverageAttendance << "\n" << mas[i].Rating << "\n" << mas[i].YearOfCreation << "\n" << mas[i].Size << "\n"
			<< mas[i].Worker << "\n" << mas[i].ValueSectors << "\n" << endl;
	}
}

void Part3()
{
	cout << "\n------------------Part 3------------------\n";

	Stadium* stadium_1 = new Stadium("Camp Nou", "Barcelona", "Laporte", "Barcelona", "football", 1, 76230.5, 9.01, 1898, 99730, 275, 38); // хип
	Stadium* stadium_2 = new Stadium("Santiago Bernabeu", "Madrid", "Peres", "Real Madrid", "football", 1, 72300.1, 9.00, 1880, 91590, 255, 36);

	Stadium stadium_3; // стек
	stadium_3.setName("Wanda Metropolitano");
	stadium_3.setAddress("Madrid");
	stadium_3.setDirector("Migel");
	stadium_3.setTeam("Atletico Madrid");
	stadium_3.setViewOfSport("football");
	stadium_3.setReserve(1);
	stadium_3.setAverageAttendance(65320.1);
	stadium_3.setRating(8.50);
	stadium_3.setYearOfCreation(1905);
	stadium_3.setSize(85000);
	stadium_3.setWorker(200);
	stadium_3.setValueSector(28);


	Stadium stats = (stadium_1, stadium_2, stadium_3);

	printInfo(*stadium_1, *stadium_2, stadium_3);

	stadium_1->serialize();
	stadium_1->deserialize();
	stadium_1->serialize("test.txt");
	stadium_1->deserialize("test.txt");

	delete stadium_1;
	delete stadium_2;
	//delete stadium_3;
}

int main()
{

	Part3();

}
