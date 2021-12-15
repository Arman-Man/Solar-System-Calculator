#pragma once

#include <iostream>
using namespace std;

class Planet
{
private:
	string name;
	double surfGrav; //relative to Earth
	double distance; //relative to Earth, in km
	double ageConst; //relative to Earth
	Planet* planets[11];
	Planet(const string&, double, double, double);	//utility function, user-created planets constructor

public:
	Planet();	//pre-set planets constructor

	Planet setName(const string&);
	Planet setSurfGrav(double);
	Planet setDistance(double);
	Planet setAgeConst(double);
	string getName() const;
	double getSurfGrav() const;
	double getDistance() const;
	double getAgeConst() const;

	void displayPlanetList() const;
	Planet& selectPlanet(int) const;	//(planet)
	bool validPlanet(int) const;		//(planet)
};
