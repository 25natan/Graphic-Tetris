//==============================================================
//The player points.
//This class holds the player points in any time of the game
//and can be updated (add or set)
//and a bar which in the points will be printed.
//==============================================================
#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <string>
#include <sstream>

class PlayerPoints {
public:
	//Set the bar for the points printing
	//and the text properties.
	PlayerPoints();

	//Draw the bar and the text on a given window
	void draw(sf::RenderWindow&);

	//Add give amount of points to the user points.
	void add(int addition);

	//Set the points to the given value.
	void set(int val);
private:

	//Set the text of the points by the format:
	//Points: ________
	//converting it first from int to string.
	void setText();

	//Player points
	int m_points;

	//The bar that the points will be printed in.
	sf::RectangleShape m_bar;

	//Font for the writing
	sf::Font m_font;

	//The text object
	sf::Text m_txt;
};