#pragma once

#include "Planet.h"
#include <iostream>
using namespace std;

class Spacecraft:public Planet
{

	friend ostream& operator<<(ostream&, const Spacecraft&);

private:
	double speed;	//in Km

public:
	Spacecraft(double = 0.0);

	Spacecraft setSpeed(double);
	double getSpeed() const;

	double calcDistance(int, int) const;	//(planet1, planet2)
	double calcTravelTime(int, int) const;	//(planet1, planet2), output in days
};