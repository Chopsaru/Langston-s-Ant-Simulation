/*****************************************************************
 ** Author: Greg Noetzel
 ** Date: 7/4/2019
 ** Description:	Constructs a 2d array game board with "edges".
 *****************************************************************/

#include "Board.hpp"
#include <iostream>

using std::endl;
using std::cout;

/*****************************************************************
 ** Description:	Default constructor initialized a dynamic array 
					and fills it with user specified characters then 
					fills in a "boundy" of '|' and '-' around it.
 *****************************************************************/
Board::Board(int cols, int rows, char fill) {
	colSize = (cols + 2);
	rowSize = (rows + 2);

	array = new char* [colSize];						//dynamic array

	for (int i = 0; i < rowSize; i++) {
		array[i] = new char[(colSize + 2)];
	}

	for (int i = 0; i < rowSize; i++) {					//fill all spaces
		for (int j = 0; j < colSize; j++) {
			array[i][j] = fill;
		}
	}

	for (int i = 0; i < (rowSize); i++) {					//filling row boundries
		array[i][0] = '|';
		array[i][(colSize - 1)] = '|';
	}
	for (int i = 0; i < (colSize); i++) {					//filling row boundries
		array[0][i] = '-';
		array[(rowSize - 1)][i] = '-';
	}
}

/*****************************************************************
 ** Description:	destructor to free mem
 *****************************************************************/
Board::~Board() {										//deconstructor
	for (int i = 0; i < rowSize; i++)
		delete[] array[i];
}

/*****************************************************************
 ** Description:	prints board
 *****************************************************************/
void Board::print() {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

//setter
void Board::setPiece(int yPos, int xPos, char item) {	
	array[yPos][xPos] = item;
}

//getter
char Board::getPiece(int yPos, int xPos) {				
	return array[yPos][xPos];
}
