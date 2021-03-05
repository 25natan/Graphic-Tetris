#include "Shape5.h"
//==============================================================
Shape5::Shape5(int row, int col, sf::Color color, Board& board)
	:GameShape(color)
{
	m_position = fst;
	m_squares[0] = Cell(row, col);
	m_squares[1] = Cell(row + 1, col - 1);
	m_squares[2] = Cell(row + 1, col);
	m_squares[3] = Cell(row + 2, col - 1);
}
//==============================================================
void Shape5::actRotate()
{
	switch (m_position)
	{
	case fst:
		m_squares[0] = Cell(m_squares[0].m_row, m_squares[0].m_col - 2);
		m_squares[2] = Cell(m_squares[2].m_row - 1, m_squares[2].m_col - 1);
		m_squares[3] = Cell(m_squares[3].m_row - 1, m_squares[3].m_col + 1);
		m_position = scnd;
		return;
	case scnd:
		m_squares[0] = Cell(m_squares[0].m_row, m_squares[0].m_col + 2);
		m_squares[2] = Cell(m_squares[2].m_row + 1, m_squares[2].m_col + 1);
		m_squares[3] = Cell(m_squares[3].m_row + 1, m_squares[3].m_col - 1);
		m_position = fst;
	}
}
//==============================================================