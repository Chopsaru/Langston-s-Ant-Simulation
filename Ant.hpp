/*********************************************************************
** Author: Greg Noetzel
** Date: 7/4/2019
** Description: Header file for ant.cpp 
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "Board.hpp"

class Ant {
private:
	int targetRow;
	int targetCol;
	int currentRow;
	int currentCol;
	int nRows;
	int nCols;
	int nSteps;
	int startRow;
	int startCol;
	char direction;
	char antColor;
	Board* antBoard;
	char targetColor;
	bool inError;

public:
	Ant();

	void getData();
	void ecGetData();
	void makeBoard();
	void nextStep();
	void runSim();
	void turnRight();
	void turnLeft();

};

#endif
