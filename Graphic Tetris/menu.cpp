#include "Menu.h"
//==============================================================
Menu::Menu()
{
	//Set the back ground for all the writing.
	m_backgroundTxtr.loadFromFile("background.png");
	m_background.setTexture(m_backgroundTxtr);

	//Set the font for all the writing.
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	//Set the color for all the writing and bars outlines.
	m_color = sf::Color(100, 100, 0);

	//Set the text style for all the writing.
	m_textStyle = sf::Text::Style::Bold;
}
//==============================================================
int Menu::run(sf::RenderWindow& window, sf::Event& event)
{
	openingWindow(window, event);
	if (window.isOpen())
		menuWindow(window, event);
	if (window.isOpen())
		lastWindow(window, event);
	return m_choise;
}
//==============================================================
void Menu::openingWindow(sf::RenderWindow& window, sf::Event& event)
{
	//create and set postion of the text
	sf::Text txt("Tetris", m_font, 230);
	txt.setPosition(120, 70);
	txt.setFillColor(m_color);
	txt.setStyle(m_textStyle);

	//display it on screen for few seconds  
	sf::Clock clock;
	while (window.isOpen() && clock.getElapsedTime().asSeconds() < 2)
	{
		window.clear();
		window.draw(m_background);
		window.draw(txt);
		window.display();
		if (window.pollEvent(event) && event.type == sf::Event::Closed)
			window.close();
	}
}
//==============================================================
void Menu::menuWindow(sf::RenderWindow& window, sf::Event& event)
{
	//create and set the position of the text
	sf::Text txt("Please choose\n a level to play!", m_font, 100);
	txt.setPosition(70, 70);
	txt.setFillColor(m_color);
	txt.setStyle(m_textStyle);

	//set level bars (rectangles) and text (numbers)
	sf::Text num[NUMBER_OF_LEVELS];
	sf::RectangleShape levelBars[NUMBER_OF_LEVELS];
	for (int i = 0;i < NUMBER_OF_LEVELS;i++)
	{
		levelBars[i].setSize(sf::Vector2f(100, 100));
		levelBars[i].setFillColor(sf::Color::Transparent);
		levelBars[i].setOutlineThickness(5);
		levelBars[i].setOutlineColor(m_color);
		num[i].setCharacterSize(70);
		num[i].setFont(m_font);
		num[i].setFillColor(m_color);
		num[i].setStyle(m_textStyle);
		char ch = '1' + i;
		num[i].setString(ch);
	}

	//set the position of the bars 4,4 in a row
	for (int i = 0;i < NUMBER_OF_LEVELS / 2;i++)
		levelBars[i].setPosition(100 + i * 150, 400);

	for (int i = 0;i < NUMBER_OF_LEVELS / 2;i++)
		levelBars[i + NUMBER_OF_LEVELS/2].setPosition(100 + i * 150, 600);

	//set the position of the numbers text by the bars
	for (int i = 0;i < NUMBER_OF_LEVELS;i++)
		num[i].setPosition(levelBars[i].getPosition().x + 20, levelBars[i].getPosition().y + 10);

	//display the level menu on screen and wait for user's choise
	while (window.isOpen())
	{
		window.clear();
		window.draw(m_background);
		window.draw(txt);
		for (int i = 0;i < 8;i++)
		{
			window.draw(levelBars[i]);
			window.draw(num[i]);
		}
		window.display();
		if (window.pollEvent(event) )
			if(event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
				for (int i = 0;i < 8;i++)
					if (levelBars[i].getGlobalBounds().contains(
						window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					{
						m_choise = i + 1;
						return;
					}
	}
}
//==============================================================
void Menu::lastWindow(sf::RenderWindow& window, sf::Event& event)
{
	sf::Text txt("Let's play!", m_font, 150);
	txt.setPosition(70, 200);
	txt.setFillColor(m_color);
	txt.setStyle(m_textStyle);


	sf::Clock clock;
	while (window.isOpen() && clock.getElapsedTime().asSeconds() < 1)
	{
		window.clear();
		window.draw(m_background);
		window.draw(txt);
		window.display();
		if (window.pollEvent(event) && event.type == sf::Event::Closed)
			window.close();
	}
}
