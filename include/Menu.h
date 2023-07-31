//==============================================================
//The start menu of the game.
//This start menu has three parts:
// Opening window - presents the title of the game for few seconds.
// Menu window - lets the user choose a level for the game.
// Last window - show up after the level choosen and says Let's play!
//All the windows use the same color and font which are initialized in the Menu's C-tor.
//When calling the function run() it calls all the windows and return user's choise.
//All the windows let the user close in any time and then the function run() will return -1.
//==============================================================

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Macros.h"

class Menu {
public:
	//Set the following things:
	//Font, Text style, Color,
	//Background's sprite and Texture.
	Menu();

	//Call the opening window and then the menu and then the last window
	//and return the choise in the end.
	int run(sf::RenderWindow& window, sf::Event& event);
private:
	//Display the opening window for few seconds
	void openingWindow(sf::RenderWindow& window, sf::Event& event);

	//Display the level menu window with bars for every level
	//and wait for the user's choise
	void menuWindow(sf::RenderWindow& window, sf::Event& event);

	//Display Let's play on the window for few seconds and finish.
	void lastWindow(sf::RenderWindow& window, sf::Event& event);

	//User level choise
	int m_choise;

	//Font for all the writing
	sf::Font m_font;

	//Color for all the writing
	sf::Color m_color;

	//Text style for all the writing
	sf::Text::Style m_textStyle;

	//Background sprite
	sf::Sprite m_background;

	//Background texture 
	sf::Texture m_backgroundTxtr;
};
