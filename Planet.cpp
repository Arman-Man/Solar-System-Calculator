#include "Planet.h"

Planet::Planet() {
	setName("None");
	setSurfGrav(0.0); //relative to Earth
	setDistance(0.0); //relative to Earth, in km
	setAgeConst(0.0); //relative to Earth, in years

	planets[0] = new Planet("Sun", 27.9, -1.4785 * pow(10, 8), 24.5);
	planets[1] = new Planet("Mercury", 0.38, -9.1691 * pow(10, 7), 88.0 / 365);
	planets[2] = new Planet("Venus", 0.91, -4.14 * pow(10, 7), 225.0 / 365);
	planets[3] = new Planet("Earth", 1.00, 0.0, 1.0);
	planets[4] = new Planet("Moon", 0.17, 3.8447 * pow(10, 5), 1 / 13.5);
	planets[5] = new Planet("Mars", 0.38, 7.834 * pow(10, 7), 687.0 / 365);
	planets[6] = new Planet("Jupiter", 2.54, 6.2873 * pow(10, 8), 12.0);
	planets[7] = new Planet("Saturn", 1.08, 1.275 * pow(10, 9), 29.5);
	planets[8] = new Planet("Uranus", 0.91, 2.724 * pow(10, 9), 84.0);
	planets[9] = new Planet("Neptune", 1.19, 4.3514 * pow(10, 9), 165.0);
	planets[10] = new Planet("Pluto", 0.06, 5.89 * pow(10, 9), 248.0);

}

Planet::Planet(const string& nm, double sg, double p, double yr) {
	setName(nm);
	setSurfGrav(sg);
	setDistance(p);
	setAgeConst(yr);
}

Planet Planet::setName(const string& nm) {
	name = nm;
	return *this;
}

Planet Planet::setSurfGrav(double sg) {
	surfGrav = sg;
	return *this;
}

Planet Planet::setDistance(double d) {
	distance = d;
	return *this;
}

Planet Planet::setAgeConst(double yr) {
	ageConst = yr;
	return *this;
}


string Planet::getName() const {
	return name;
}

double Planet::getSurfGrav() const {
	return surfGrav;
}

double Planet::getDistance() const {
	return distance;
}

double Planet::getAgeConst() const {
	return ageConst;
}

void Planet::displayPlanetList() const {
	cout << "Planet List\n0. Sun\n1. Mercury\n2. Venus\n3. Earth\n4. Moon\n5. Mars\n6. Jupiter\n7. Saturn\n8. Uranus\n9. Neptune\n10. Pluto" << endl;
}

Planet& Planet::selectPlanet(int planet) const {
	return *planets[planet];
}

bool Planet::validPlanet(int userInput) const {
	if (userInput >= 0 && userInput <= 10) {
		return true;
	}
	else {
		return false;
	}
}
