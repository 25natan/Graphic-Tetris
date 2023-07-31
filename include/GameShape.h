//==============================================================
//The main shape object of the game 
//made of 4 squares positioned in some diffrent order.
//Every shape can move down, right or left.
//Every shape can also be rotated in a secific way and get 1-4 diffrent positions.
//The actull squares are in the game board matrix and the shape object contains
//an array of cells in this matrix.
//==============================================================

#pragma once
#include "Board.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>

//Possible movements of game shape.
enum Movement { right, left, down };

//Possible positions.
enum Position { fst, scnd, thrd, frth };

//Number of squares in every game shape.
const int NUM_OF_SQUARES = 4;

class GameShape {
public:

	//Set the color of the shape
	//by setting the color of each square of the shape.
	GameShape(sf::Color color);

	//Draw the shape on the board square by square
	//using Board.draw() function for every square.
	void draw(Board& board) const;

	//Clean the shape on the board square by square
	//using Board.clean() function for every square.
	void clean(Board& board) const;

	//Checks the shape's place on the board is clean
	//square by square using Board.isClean() function for every square.
	bool isClean(const Board& board) const;

	//If the shape's place after the rotation is clean
	//then the function rotates it and return true,
	//otherwise the shape won't be rotated and false will be returned
	bool rotate(Board& board);

	//If the shape's place after the movement is clean
	//then the function moves it and return true,
	//otherwise the shape won't be moved and false will be returned
	bool move(Movement movement, Board& board);

    virtual ~GameShape(){}
protected:

	//Do the actual move
	void actMove(Movement);

	//Do the actual rotation
	virtual void actRotate() = 0;

	//4 cell on the board matrix representing the squares on the board
	Cell m_squares[NUM_OF_SQUARES];

	//The current position
	Position m_position;

	//The shape's color
	sf::Color m_color;
};