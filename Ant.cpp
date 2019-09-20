/*********************************************************************
** Author: Greg Noetzel
** Date: 7/4/2019
** Description: Contails all ant class functions including the default constructor, 
				getData, ecGetData, makeBoard, turnRight, turnLeft, nextStep, and runSim.
*********************************************************************/

#include "Ant.hpp"
#include "Board.hpp"
#include "Menus.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;


/*****************************************************************
 ** Description:	Default constructor initializes the data not input by user.
 *****************************************************************/
Ant::Ant() {
	antColor = ' ';
	direction = 'n';
}


/*****************************************************************
 ** Description:	gets data from user for standard ant sim
 *****************************************************************/
void Ant::getData() {
	do {														//validation loops adapted from https://stackoverflow.com/questions/2075898/good-input-validation-loop-using-cin-c
		inError = false;
		cout << "How many rows on the board?" << endl;
		cin >> nRows;
		if (cin.fail()) {
			inError = true;
			cout << "Enter a valid integer" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (inError == true);

	do {
		inError = false;
		cout << "How many columns on the board?" << endl;
		cin >> nCols;
		if (cin.fail()) {
			inError = true;
			cout << "Enter a valid integer" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (inError == true);

	do {
		inError = false;
		cout << "How many steps should the sim run for?" << endl;
		cin >> nSteps;
		if (cin.fail()) {
			inError = true;
			cout << "Enter a valid integer" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (inError == true);

	do {
		inError = false;
		cout << "What row will the ant start in?" << endl;
		cin >> startRow;
		if (cin.fail() || (startRow > nRows)) {
			inError = true;
			cout << "Enter a valid integer" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (inError == true);

	do {
		inError = false;
		cout << "What column will the ant start in?" << endl;
		cin >> startCol;
		if (cin.fail() || (startCol > nCols)) {
			inError = true;
			cout << "Enter a valid integer" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (inError == true);
}

/*****************************************************************
 ** Description:	gets data from user for Extre Credit ant sim
 *****************************************************************/
void Ant::ecGetData() {
	do {
		inError = false;
		cout << "How many rows on the board?" << endl;
		cin >> nRows;
		if (cin.fail()) {
			inError = true;
			cout << "Enter a valid integer" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (inError == true);

	do {
		inError = false;
		cout << "How many columns on the board?" << endl;
		cin >> nCols;
		if (cin.fail()) {
			inError = true;
			cout << "Enter a valid integer" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (inError == true);

	do {
		inError = false;
		cout << "How many steps should the sim run for?" << endl;
		cin >> nSteps;
		if (cin.fail()) {
			inError = true;
			cout << "Enter a valid integer" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (inError == true);

	srand(time(0));
	startRow = (rand() % nRows);
	startCol = (rand() % nCols);
}

/*****************************************************************
 ** Description:	initializes a new board class  and sets the ant 
					on its user specified location
 *****************************************************************/
void Ant::makeBoard() {
	antBoard = new Board(nCols, nRows, ' ');
	currentRow = startRow;
	currentCol = startCol;
	antBoard->setPiece(startCol, startRow, '*');

	antBoard->print();											//prints board to show user initial ant position
}

void Ant::turnRight() {
	if (direction == 'n') {
		direction = 'e';
		targetCol = currentCol;
		targetRow = (currentRow+1);
	}
	else if (direction == 'e') {
		direction = 's';
		targetCol = (currentCol+1);
		targetRow = currentRow;
	}
	else if (direction == 's') {
		direction = 'w';
		targetCol = currentCol;
		targetRow = (currentRow-1);
	}
	else if (direction == 'w') {
		direction = 'n';
		targetCol = (currentCol-1);
		targetRow = currentRow;
	}
}

void Ant::turnLeft() {
	if (direction == 'n') {
		direction = 'w';
		targetCol = currentCol;
		targetRow = (currentRow-1);
	}
	else if (direction == 'e') {
		direction = 'n';
		targetCol = currentCol;
		targetRow = (currentRow-1);
	}
	else if (direction == 's') {
		direction = 'e';
		targetCol = currentCol;
		targetRow = (currentRow+1);
	}
	else if (direction == 'w') {
		direction = 's';
		targetCol = (currentCol+1);
		targetRow = currentRow;
	}
}

/*****************************************************************
 ** Description:	update current space on Board to be the oposite 
					of anyColor
 *****************************************************************/
void Ant::nextStep() {
	if (antColor == ' ') {
		turnRight();
		antBoard->setPiece(currentCol, currentRow, '#');
	}
	else if (antColor == '#') {
		turnLeft();
		antBoard->setPiece(currentCol, currentRow, ' ');
	}

	while (((antBoard->getPiece(targetCol, targetRow)) != '#') && 
			(antBoard->getPiece(targetCol, targetRow)) != ' '){			//check for edges, 180 if detected 
		turnLeft();
		turnLeft();
	}

	targetColor = antBoard->getPiece(targetCol, targetRow);				//log targetColor

	antBoard->setPiece(targetCol, targetRow, '*');						//move Ant

	currentCol = targetCol;												//update ant coord
	currentRow = targetRow;

	antColor = targetColor;												//update antColor
}

/*****************************************************************
 ** Description:	Runs simulation for specified loops then frees mem
 *****************************************************************/
void Ant::runSim() {
	makeBoard();
	for (int i = 0; i < nSteps; i++) {
		nextStep();
		antBoard->print();
	}
	
	delete antBoard;													//free mem
}