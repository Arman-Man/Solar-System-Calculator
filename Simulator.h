#pragma once

#include "Planet.h"
#include "Person.h"
#include "Spacecraft.h"
#include <iostream>
using namespace std;

class Simulator
{
private:
	Person personObj;
	Spacecraft spacecraftObj;
	static int simulationNum;

public:
	Simulator();
	Simulator(const Person&, const Spacecraft&);

	Simulator setPersonObj(const Person&);
	Simulator setSpaceCraftObj(const Spacecraft&);
	Person getPersonObj() const;
	Spacecraft getSpaceCraftObj() const;

	void createSimulationFile(int, int);			//(Planet1, Planet2)

	void displaySimulationResults(int, int) const;	//(Planet1, Planet2)
};