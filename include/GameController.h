//==============================================================
//The game controlling center.
//This object realy manages the game using the other classes - board and shapes and menu.
//It call a menu to let the user choose a level and then start playing doing the following steps:
// 1:
//    Set a new board for the whole game.
// 2:
//   Inside a loop, cteate a random shape with a random color and put it in the top of the board.
//   If it's not clean there then the game is over and it comes to the menu again.
// 3:
//   If it's clean in the top, move it down as long as it clean and let the user play
//   in limitted time between.
// 4:
//   When the shape got to the bottom then chack if a row (or some) became full and if it did then
//   delete it and raise the points of the user.
//The waiting time between movements is calculated like this:
//There is a variable levelsDifTime which is the diffrence in time between level to level, so I calculate:
//               waitingTime = maxWaitingTime - level*levelsDifTime.
//==============================================================
#pragma once
#include "Shape1.h"
#include "Shape2.h"
#include "Shape3.h"
#include "Shape4.h"
#include "Shape5.h"
#include "Board.h"
#include "Macros.h"
#include "Menu.h"
#include "PlayerPoints.h"

class GameController {
public:

	GameController();

	//Run the game using all the functions and members below.
	//Creates a random shape using randomShape function.
	//Moves the shape down using shape_abs.move() function.
	//Lets the user play between movments down using userPlay() function.
	//Dispalys the game's window using display() function.
	//Removes full rows (if there are any) using removeFullRow() function.
	void run();

private:

	//Display the window of the game using Board.display() function.
	//This function also write the current points on the window befor displaying
	void display();

	//Let user play in limitted time 
	//determinated by the choosen level.
	//Use display() function after every change that the user made.
	void userPlay();

	//Chacks if there are any full rows using Board.isFullRow() function
	//and if there are, then remove them using Board.cleanRowOfSqrs()
	//function.
	//If a row was moved it adds to the user's points this: m_level*10.
	void removeFullRow();

	//Randomly allocates memory for a spesific shape and return
	//a pointer of type Shape_abs that points to this shape
	GameShape* randomShape();

	//Return a random color one of for
	sf::Color randomColor() const;

	//level of the game
	int m_level;

	//Time for the user to play between movement down
	time_t m_waitTime, m_maxWaitTime = 400, m_levelsDifTime = 40;

	//Board of the game
	Board m_board;

	//The moving shape in any time
	GameShape* m_shape;

	//Menu for opening the game nad choosing level
	Menu m_menu;

	//The player's points (information and drawable bar)
	PlayerPoints m_playerPoints;

	//The main widow shows the game
	sf::RenderWindow m_window;

	//Event for closing or pressing keys
	sf::Event m_event;
};