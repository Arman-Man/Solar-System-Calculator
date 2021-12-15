#include "Person.h"

ostream& operator<<(ostream& output, const Person& prsnObj) {
	output << "Age: " << prsnObj.getAge() << " (years)"
		<< "\nMass: " << prsnObj.getMass() << " (kg)"
		<< "\nJump Height: " << prsnObj.getJumpHeight() << " (m)" << endl;
	return output;
}

Person::Person(double a, double m, double jh) {
	setAge(a);
	setMass(m);
	setJumpHeight(jh);
}

Person Person::setAge(double a) {
	age = a;
	return *this;
}

Person Person::setMass(double m) {
	mass = m;
	return *this;
}

Person Person::setJumpHeight(double jh) {
	jumpHeight = jh;
	return *this;
}

double Person::getAge() const {
	return age;
}

double Person::getMass() const {
	return mass;
}

double Person::getJumpHeight() const {
	return jumpHeight;
}

double Person::calcAgeOnPlanet(int planet1) const {
	Planet p1 = selectPlanet(planet1);
	return getAge() / p1.getAgeConst();
}

double Person::calcMassOnPlanet(int planet1) const {
	Planet p1 = selectPlanet(planet1);
	return p1.getSurfGrav() * getMass();
}

double Person::calcJumpHeightOnPlanet(int planet1) const {
	Planet p1 = selectPlanet(planet1);
	return getJumpHeight() / p1.getSurfGrav();
}
