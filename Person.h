#pragma once

#include "Planet.h"
#include <iostream>
using namespace std;

class Person:public Planet
{

	friend ostream& operator<<(ostream&, const Person&);

private:
	double age;		//years
	double mass;	//kg
	double jumpHeight;	//km

public:
	Person(double = 0.0, double = 0.0, double = 0.0);

	Person setAge(double);
	Person setMass(double);
	Person setJumpHeight(double);
	double getAge() const;
	double getMass() const;
	double getJumpHeight() const;

	double calcAgeOnPlanet(int) const;			//(planet)
	double calcMassOnPlanet(int) const;			//(planet)
	double calcJumpHeightOnPlanet(int) const;	//(planet)
};
