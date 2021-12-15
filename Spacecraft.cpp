#include "Spacecraft.h"

ostream& operator<<(ostream& output, const Spacecraft& spceObj) {
	output << "Spacecraft speed: " << spceObj.getSpeed() << " (m)" << endl;
	return output;
}

Spacecraft::Spacecraft(double s) {
	setSpeed(s);
}

Spacecraft Spacecraft::setSpeed(double s) {
	speed = s;
	return *this;
}

double Spacecraft::getSpeed() const {
	return speed;
}

double Spacecraft::calcDistance(int planet1, int planet2) const {
	Planet p1 = selectPlanet(planet1);
	Planet p2 = selectPlanet(planet2);

	if (p1.getDistance() >= 0 && p2.getDistance() >= 0 || p1.getDistance() < 0 && p2.getDistance() < 0) {
		return abs(abs(p1.getDistance()) - abs(p2.getDistance()));
	}
	else if (p1.getDistance() < 0 && p2.getDistance() >= 0 || p1.getDistance() >= 0 && p2.getDistance() < 0) {
		return abs(p1.getDistance()) + abs(p2.getDistance());
	}

}

double Spacecraft::calcTravelTime(int planet1, int planet2) const {
	return (calcDistance(planet1, planet2) / getSpeed()) / 24;
}
