#include "Planet.h"
#include "Person.h"
#include "Spacecraft.h"
#include "Simulator.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	char inputMenu;
	int inputPlanet1;
	int inputPlanet2;
	double inputAge;
	double inputMass;
	double inputJumpHeight;
	double inputSpeed;
	Planet planetObj;
	Person personObj;
	Spacecraft spacecraftObj;
	Simulator simulatorObj;

	do {
		cout << "Select an option between (0-5) or enter 'q' to exit" << endl
			<< "\n-Simulation-\n0.Earth Simulation" << endl
			<< "\n-Individual Tools-\n1.Age on Planet" << endl
			<< "2.Mass on Planet" << endl
			<< "3.Jump Height on Planet" << endl
			<< "4.Distance Between Planets" << endl
			<< "5.Travel Time Between Planets" << endl
			<< "\n-Quit-\nq.Exit Program\n" << endl;
		cin >> inputMenu;

		if (inputMenu == '0') {
			cout << "\n----------\n";
			cout << "\n-Earth Simulation-\n\n";
			cout << "Enter person age on Earth (years): ";
			cin >> inputAge;
			cout << "Enter person mass on Earth (kg): ";
			cin >> inputMass;
			cout << "Enter person jump height on Earth (m): ";
			cin >> inputJumpHeight;
			personObj = Person(inputAge, inputMass, inputJumpHeight);

			cout << "Enter spacecraft speed (km/hr): ";
			cin >> inputSpeed;
			spacecraftObj.setSpeed(inputSpeed);

			cout << endl;
			planetObj.displayPlanetList();
			cout << "\nEnter planet: ";
			cin >> inputPlanet1;

			while (planetObj.validPlanet(inputPlanet1) == false) {
				cout << "\nInvalid selection.\nEnter planet: ";
				cin >> inputPlanet1;
			}

			simulatorObj = Simulator(personObj, spacecraftObj);
			simulatorObj.displaySimulationResults(3, inputPlanet1);	//3 = earth
			cout << "\n";
			simulatorObj.createSimulationFile(3, inputPlanet1);	//3 = earth
			cout << "\n----------\n\n";
		}
		else if (inputMenu == '1') {
			cout << "\n----------\n";
			cout << "\n-Age on Planet-\n\n";
			cout << "Enter person age on Earth (years): ";
			cin >> inputAge;

			cout << endl;
			planetObj.displayPlanetList();
			cout << "\nEnter planet: ";
			cin >> inputPlanet1;

			while (planetObj.validPlanet(inputPlanet1) == false) {
				cout << "\nInvalid selection.\nEnter planet: ";
				cin >> inputPlanet1;
			}

			personObj.setAge(inputAge);
			cout << "\nAge on " << personObj.selectPlanet(inputPlanet1).getName() << ": "
				<< fixed << setprecision(1) << personObj.calcAgeOnPlanet(inputPlanet1) << " (years)" << endl;
			cout << "\n----------\n\n";
		}
		else if (inputMenu == '2') {
			cout << "\n----------\n";
			cout << "\n-Mass on Planet-\n\n";
			cout << "Enter person mass on Earth (kg): ";
			cin >> inputMass;

			cout << endl;
			planetObj.displayPlanetList();
			cout << "\nEnter planet: ";
			cin >> inputPlanet1;

			while (planetObj.validPlanet(inputPlanet1) == false) {
				cout << "\nInvalid selection.\nEnter planet: ";
				cin >> inputPlanet1;
			}

			personObj.setMass(inputMass);
			cout << "\nMass on " << personObj.selectPlanet(inputPlanet1).getName() << ": "
				<< fixed << setprecision(1) << personObj.calcMassOnPlanet(inputPlanet1) << " (kg)" << endl;
			cout << "\n----------\n\n";
		}
		else if (inputMenu == '3') {
			cout << "\n----------\n";
			cout << "\n-Jump Height on Planet-\n\n";
			cout << "Enter person jump height on Earth (m): ";
			cin >> inputJumpHeight;

			cout << endl;
			planetObj.displayPlanetList();
			cout << "\nEnter planet: ";
			cin >> inputPlanet1;

			while (planetObj.validPlanet(inputPlanet1) == false) {
				cout << "\nInvalid selection.\nEnter planet: ";
				cin >> inputPlanet1;
			}

			personObj.setJumpHeight(inputJumpHeight);
			cout << "\nJump height on " << personObj.selectPlanet(inputPlanet1).getName() << ": "
				<< fixed << setprecision(1) << personObj.calcJumpHeightOnPlanet(inputPlanet1) << " (m)" << endl;
			cout << "\n----------\n\n";
		}
		else if (inputMenu == '4') {
			cout << "\n----------\n";
			cout << "\n-Distance Between Planets-\n\n";

			planetObj.displayPlanetList();
			cout << "\nEnter starting planet: ";
			cin >> inputPlanet1;

			while (planetObj.validPlanet(inputPlanet1) == false) {
				cout << "\nInvalid selection.\nEnter planet: ";
				cin >> inputPlanet1;
			}

			cout << "Enter ending planet: ";
			cin >> inputPlanet2;

			while (planetObj.validPlanet(inputPlanet2) == false) {
				cout << "\nInvalid selection.\nEnter planet: ";
				cin >> inputPlanet2;
			}

			cout << "\nDistance between " << spacecraftObj.selectPlanet(inputPlanet1).getName() << " and "
				<< spacecraftObj.selectPlanet(inputPlanet2).getName() << ": "
				<< fixed << setprecision(0) << spacecraftObj.calcDistance(inputPlanet1, inputPlanet2) << " (km)" << endl;
			cout << "\n----------\n\n";
		}
		else if (inputMenu == '5') {
			cout << "\n----------\n";
			cout << "\n-Travel Time Between Planets-\n\n";
			cout << "Enter spacecraft speed (km/hr): ";
			cin >> inputSpeed;
			cout << endl;
			spacecraftObj.setSpeed(inputSpeed);

			planetObj.displayPlanetList();
			cout << "\nEnter starting planet: ";
			cin >> inputPlanet1;

			while (planetObj.validPlanet(inputPlanet1) == false) {
				cout << "\nInvalid selection.\nEnter planet: ";
				cin >> inputPlanet1;
			}

			cout << "Enter ending planet: ";
			cin >> inputPlanet2;

			while (planetObj.validPlanet(inputPlanet2) == false) {
				cout << "\nInvalid selection.\nEnter planet: ";
				cin >> inputPlanet2;
			}

			cout << "\nTravel time from " << spacecraftObj.selectPlanet(inputPlanet1).getName() << " and "
				<< spacecraftObj.selectPlanet(inputPlanet2).getName() << ": "
				<< fixed << setprecision(0) << spacecraftObj.calcTravelTime(inputPlanet1, inputPlanet2) << " (days)" << endl;
			cout << "\n----------\n\n";
		}
		else if (inputMenu != 'q' && inputMenu != 'Q') {
			cout << "\nInvalid input!\n" << endl;
		}
	} while (inputMenu != 'q' && inputMenu != 'Q');
	
	return 0;
}