#include "../include/Board.h"
//==============================================================
Board::Board()
	:m_board(ROWS, std::vector<sf::RectangleShape>(COLS))
{
	for (int i = 0;i < ROWS;i++)
		for (int j = 0;j < COLS;j++)
		{
			m_board[i][j].setPosition(j * SQR_SIZE, i * SQR_SIZE);
			m_board[i][j].setSize(sf::Vector2f(SQR_SIZE, SQR_SIZE));
			m_board[i][j].setFillColor(EMPTY);
			m_board[i][j].setOutlineColor(BLACK);
		}
}
//==============================================================
void Board::draw(Cell cell, sf::Color color)
{
	m_board[cell.m_row][cell.m_col].setFillColor(color);
	m_board[cell.m_row][cell.m_col].setOutlineThickness(1);
}
//==============================================================
void Board::clean(Cell cell)
{
	m_board[cell.m_row][cell.m_col].setFillColor(EMPTY);
	m_board[cell.m_row][cell.m_col].setOutlineThickness(0);

}
//==============================================================
bool Board::isClean(Cell cell) const
{
	//If the given location is not on board then return false as
	//if it was on board but not clean.
	if (cell.m_col < 0 || cell.m_col >= COLS || cell.m_row < 0 || cell.m_row >= ROWS)
		return false;
	bool f = m_board[cell.m_row][cell.m_col].getFillColor() == EMPTY;
	return f;
}
//==============================================================
void Board::draw(sf::RenderWindow& window) const
{
	for (int i = 0;i < ROWS;i++)
		for (int j = 0;j < COLS;j++)
			window.draw(m_board[i][j]);
}
//==============================================================
bool Board::isFullRow(int rowNumber)
{
	for (int i = 0;i < COLS;i++)
		if (isClean(Cell(rowNumber, i)))
			return false;
	return true;
}
//==============================================================
void Board::cleanRow(int rowNumber)
{
	while (rowNumber)
	{
		for (int i = 0;i < COLS;i++)
		{
			m_board[rowNumber][i].setFillColor(m_board[rowNumber - 1][i].getFillColor());
			m_board[rowNumber][i].setOutlineThickness(m_board[rowNumber - 1][i].getOutlineThickness());
		}
		rowNumber--;
	}
	for (int i = 0;i < COLS;i++)
		m_board[0][i].setFillColor(EMPTY);
}
//==============================================================
