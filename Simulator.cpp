#include "Simulator.h"
#include <iomanip>
#include <string>
#include <fstream>

int Simulator::simulationNum;

Simulator::Simulator() {
	Person obj1;
	Spacecraft obj2;
	setPersonObj(obj1);
	setSpaceCraftObj(obj2);
}

Simulator::Simulator(const Person& obj1, const Spacecraft& obj2) {
	setPersonObj(obj1);
	setSpaceCraftObj(obj2);
}

Simulator Simulator::setPersonObj(const Person& obj) {
	personObj = obj;
	return *this;
}

Simulator Simulator::setSpaceCraftObj(const Spacecraft& obj) {
	spacecraftObj = obj;
	return *this;
}

Person Simulator::getPersonObj() const {
	return personObj;
}

Spacecraft Simulator::getSpaceCraftObj() const {
	return spacecraftObj;
}

void Simulator::createSimulationFile(int p1, int p2) {	//p1 is my Earth (3), p2 is the user input
	simulationNum++;
	string fileName = "Simulation_" + to_string(simulationNum);

	fstream file;
	file.open(fileName, ios::out);

	file << "***Earth Simulation Report***" << endl;
	file << "\n*Starting planet* (" << getSpaceCraftObj().selectPlanet(p1).getName() << ")" << endl;
	file << personObj;
	file << spacecraftObj;

	file << "\n*New planet* (" << getSpaceCraftObj().selectPlanet(p2).getName() << ")" << "\nAge: " << fixed << setprecision(1) << getPersonObj().calcAgeOnPlanet(p2)
		<< " (years)" << endl
		<< "Mass: " << getPersonObj().calcMassOnPlanet(p2) << " (kg)" << endl
		<< "Jump Height: " << getPersonObj().calcJumpHeightOnPlanet(p2) << " (m)" << endl

		<< "Distance between " << getSpaceCraftObj().selectPlanet(p1).getName() << " and "
		<< getSpaceCraftObj().selectPlanet(p2).getName() << ": " << fixed << setprecision(0) << getSpaceCraftObj().calcDistance(p1, p2) << " (m)" << endl

		<< "Travel time from " << getSpaceCraftObj().selectPlanet(p1).getName() << ": " << getSpaceCraftObj().calcTravelTime(p1, p2) << " (days)" << endl;

	file.close();

	cout << "File: " << fileName << "\nHas been updated." << endl;
}

void Simulator::displaySimulationResults(int p1, int p2) const {

	cout << "\n***Earth Simulation Report***\n\n";

	cout << "*Starting planet* (" << getSpaceCraftObj().selectPlanet(p1).getName() << ")" << endl;
	cout << personObj;
	cout << spacecraftObj;

	cout << "\n*New planet* (" << getSpaceCraftObj().selectPlanet(p2).getName() << ")" << endl;
	cout << "Age: " << fixed << setprecision(1) << getPersonObj().calcAgeOnPlanet(p2) << " (years)" << endl
		<< "Mass: " << getPersonObj().calcMassOnPlanet(p2) << " (kg)" << endl
		<< "Jump Height: " << getPersonObj().calcJumpHeightOnPlanet(p2) << " (m) " << endl

		<< "Distance between " << getSpaceCraftObj().selectPlanet(p1).getName() << " and "
		<< getSpaceCraftObj().selectPlanet(p2).getName() << ": " << fixed << setprecision(0)
		<< getSpaceCraftObj().calcDistance(p1, p2) << " (km)" << endl

		<< "Travel time from " << getSpaceCraftObj().selectPlanet(p1).getName() << ": " << getSpaceCraftObj().calcTravelTime(p1, p2) << " (days)" << endl;
}