#include "../include/PlayerPoints.h"

PlayerPoints::PlayerPoints()
{
	//Set the size of the points bar.
	m_bar.setSize(sf::Vector2f(COLS * SQR_SIZE, POINTS_BAR_WIDTH));

	//Set the position of the points bar.
	m_bar.setPosition(0, ROWS * SQR_SIZE);

	//Set the backghround color of the points bar.
	m_bar.setFillColor(sf::Color::White);

	//Set the font for the points bar.
	m_font.loadFromFile("./resources/Arial.ttf");

	//Set the character size.
	m_txt.setCharacterSize(60);

	//Set the points text font.
	m_txt.setFont(m_font);

	//Set the text position inside the bar.
	m_txt.setPosition(m_bar.getPosition().x + 50, m_bar.getPosition().y + 10);

	//Set the color of the text to black.
	m_txt.setFillColor(sf::Color::Black);
}
void PlayerPoints::draw(sf::RenderWindow& window)
{
	window.draw(m_bar);
	window.draw(m_txt);
}
void PlayerPoints::add(int addition)
{
	m_points += addition;
	setText();
}
void PlayerPoints::set(int points)
{
	m_points = points;
	setText();
}
void PlayerPoints::setText()
{
	std::ostringstream sstr;
	sstr << m_points;
	m_txt.setString("Points: " + sstr.str());
}
