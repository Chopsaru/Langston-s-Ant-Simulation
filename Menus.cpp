/*********************************************************************
** Author: Greg Noetzel
** Date: 7/4/2019
** Description: Contains all menu functions. calls relevant ant class 
				methods based on user menu selections
*********************************************************************/

#include <iostream>
#include "Ant.hpp"
#include "Board.hpp"
#include "Menus.hpp"

using std::cout;
using std::cin;
using std::endl;

void mainMenu() {
	int mmChoice;
	bool menuError;

	cout << endl << "Main Menu" << endl;									//main menu prompt
	cout << "=========" << endl << endl;
	cout << "Please select one of the following" << endl << endl;

	cout << "1. Lanfton's Ant Simulation" << endl;							//menu options
	cout << "2. Quit" << endl << endl;

	do {
		menuError = false;
		cin >> mmChoice;
		if (cin.fail() || ((mmChoice != 1) && (mmChoice != 2))) {			//option validation
			menuError = true;
			cout << "Input error. Enter one of the menu numbers." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (menuError == true);

	switch (mmChoice) {														//submenu switch
	case 1:	
		antMenu();
		break;
	case 2:
		exit(0);
		break;
	}
}

void antMenu() {															//submenu
	int amChoice = 0;
	int playAgain;
	bool menuError;
	Ant ant;

	cout << endl << "Langton's Ant Sim" << endl;							//ant menu prompts
	cout << "=========" << endl << endl;
	cout << "Please select one of the following" << endl << endl;
		
	cout << "1. Start Langton's Ant Simulation" << endl;
	cout << "2. Start Extra Credit Ant Simulation" << endl;
	cout << "3. Go back" << endl;
	cout << "4. Quit" << endl;

	
	do {
		menuError = false;													//option validation
		cin >> amChoice;
		if (cin.fail() || ((amChoice != 1) && (amChoice != 2) && (amChoice != 3) && (amChoice != 4))) {
			menuError = true;
			cout << "Input error. Enter one of the menu numbers." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (menuError == true);

	switch (amChoice) {
		case 1:																//Starts standard ant sim
			ant.getData();
			ant.runSim();

			cout << "1. Play again" << endl;
			cout << "2. Quit" << endl;

			do {															//more option validation
				menuError = false;
				cin >> playAgain;
				if (cin.fail() || ((amChoice != 1) && (amChoice != 2))) {
					menuError = true;
					cout << "Input error. Enter one of the menu numbers." << endl;
					cin.clear();
					cin.ignore(100, '\n');
				}
			} while (menuError == true);

			switch (playAgain){												//play again switch
				case 1:
					antMenu();
				case 2:
					exit(0);
			}
			break;
		case 2:																//Start EC ant sim
			ant.ecGetData();
			ant.runSim();

			cout << endl << "Choose." << endl;
			cout << "1. Play again" << endl;
			cout << "2. Quit" << endl;

			do {
				menuError = false;											//option validation
				cin >> playAgain;
				if (cin.fail() || ((amChoice != 1) && (amChoice != 2))) {
					menuError = true;
					cout << "Input error. Enter one of the menu numbers." << endl;
					cin.clear();
					cin.ignore(100, '\n');
				}
			} while (menuError == true);

			switch (playAgain) {
				case 1:
					antMenu();
				case 2:
					exit(0);
			}
			break;
		case 3:
			mainMenu();														//go back
			break;
		case 4:																//quit
			exit(0);
			break;
	}
}
