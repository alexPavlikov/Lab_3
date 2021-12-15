#pragma once
#include "SportsFacility.h"
#include "ISeasonTicketProvider.h"

using namespace std;

class Court : public SportsFacility, public ISeasonTicketProvider
{
public:
	Court();
	Court(string address, int capacity, float attendance, string TypeOfCoverage);

	void setSeasonTickets(int SeasonTickets) override;
	void ticket() override;

	friend ostream& operator<< (ostream& out, const Court& s);
};

