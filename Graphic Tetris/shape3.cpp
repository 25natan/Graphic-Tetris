#include "Shape3.h"
//==============================================================
Shape3::Shape3(int row, int col, sf::Color color, Board& board)
	:GameShape(color)
{
	m_squares[0] = Cell(row, col);
	m_squares[1] = Cell(row + 1, col);
	m_squares[2] = Cell(row, col + 1);
	m_squares[3] = Cell(row + 1, col + 1);
}
//==============================================================