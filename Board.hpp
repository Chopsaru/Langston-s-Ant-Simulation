/*********************************************************************
** Author: Greg Noetzel
** Date: 7/4/2019
** Description: Header file for Board.cpp initializes 
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
	private:
		int colSize = 0;
		int rowSize = 0;
		char** array;

	public:
		Board(int cols, int rows, char fill);
		~Board();

		void print();
		void setPiece(int ,int, char);
		char getPiece(int ,int);
};

#endif
