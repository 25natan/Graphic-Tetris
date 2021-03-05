#include "Shape1.h"
//==============================================================
Shape1::Shape1(int row, int col, sf::Color color, Board& board)
	:GameShape(color)
{
	m_position = fst;
	m_squares[0] = Cell(row, col);
	m_squares[1] = Cell(row + 1, col - 1);
	m_squares[2] = Cell(row + 1, col);
	m_squares[3] = Cell(row + 1, col + 1);
}
//==============================================================
void Shape1::actRotate()
{
	m_squares[1] = m_squares[0];
	m_squares[0] = m_squares[3];
	switch (m_position)
	{
	case fst:
		m_squares[3] = Cell(m_squares[3].m_row + 1, m_squares[3].m_col - 1);
		m_position = scnd;
		return;
	case scnd:
		m_squares[3] = Cell(m_squares[3].m_row - 1, m_squares[3].m_col - 1);
		m_position = thrd;
		return;
	case thrd:
		m_squares[3] = Cell(m_squares[3].m_row - 1, m_squares[3].m_col + 1);
		m_position = frth;
		return;
	case frth:
		m_squares[3] = Cell(m_squares[3].m_row + 1, m_squares[3].m_col + 1);
		m_position = fst;
		return;
	}
}
//==============================================================