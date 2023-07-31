//==============================================================
//The main board of the game,
//made of 2D vector (a matrix) of squares called m_board, such
//that all the game is based on these squares - the shapes and the rest of the space.
//There is a default color called 'EMPTY' (defined in Macros.h) represents a "clean" square
//and a square can be drawn in other given color, one of these that defined also in the Macros.h.
//Square with a color diffrent from hte default one is considered a "full" square.
//For the use of the squares in the board matrix a type Cell is declared below
//which represent the square in any cell in the matrix 
//==============================================================

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Macros.h"


//type represent a cell in the board matrix
struct Cell {
	Cell(int i, int j) :m_row(i), m_col(j) {}
	Cell() = default;
	int m_row;
	int m_col;
};


class Board {
public:

	//Initialize the vector 'm_board' to be ROWS X COLS of
	//rectangles every one of them in size SQR_SIZE and EMPTY color .
	Board();

	//Set the color of the square in m_board in the given cell
	//to the given color.
	void draw(Cell cell, sf::Color);

	//Set the color of the square in m_board in the given cell
	//to the EMPTY color.
	void clean(Cell cell);

	//Checks if the square in m_board in the given cell
	//is colored with the EMPTY color or not.
	bool isClean(Cell cell) const;

	//Checks if all the squares in m_board in the row with the given number
	//are colored with colors diffrent from the EMPTY color.
	bool isFullRow(int rowNumber);

	//For each row in m_board form the upper row to the row with the given number,
	//copy to it the row above it.
	void cleanRow(int rowNumber);

	//Draw the board on given window.
	void draw(sf::RenderWindow&) const;

private:
	std::vector <std::vector<sf::RectangleShape>> m_board;
};


