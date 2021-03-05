#include "GameShape.h"
//==============================================================
GameShape::GameShape(sf::Color color)
	:m_color(color)
{}
//==============================================================
void GameShape::draw(Board& board) const
{
	board.draw(m_squares[0], m_color);
	board.draw(m_squares[1], m_color);
	board.draw(m_squares[2], m_color);
	board.draw(m_squares[3], m_color);
}
//==============================================================
void GameShape::clean(Board& board) const
{
	board.clean(m_squares[0]);
	board.clean(m_squares[1]);
	board.clean(m_squares[2]);
	board.clean(m_squares[3]);
}
//==============================================================
bool GameShape::isClean(const Board& board) const
{
	return board.isClean(m_squares[0]) &&
		board.isClean(m_squares[1]) &&
		board.isClean(m_squares[2]) &&
		board.isClean(m_squares[3]);
}
//==============================================================
bool GameShape::move(Movement movement, Board& board)
{
	//Keep the current squares in temporary array
	//befor moving them.
	Cell temp[]{ m_squares[0],m_squares[1],m_squares[2],m_squares[3] };

	//Keep the current position in temporary variable.
	Position tempPos = m_position;

	//clean current place 
	clean(board);

	//Actually move.
	actMove(movement);

	//If the board in thie place isn't clean then restor the last squares 
	//kept in temp array and draw th shape again in the same place
	if (!isClean(board))
	{
		m_squares[0] = temp[0];
		m_squares[1] = temp[1];
		m_squares[2] = temp[2];
		m_squares[3] = temp[3];
		m_position = tempPos;
		draw(board);
		//Can't be moved.
		return false;
	}

	//Draw the shape in the new place
	draw(board);

	//Moving succeed.
	return true;
};
//==============================================================
bool GameShape::rotate(Board& board)
{
	//Keep the current squares in temporary array
	//befor rotating.
	Cell temp[]{ m_squares[0],m_squares[1],m_squares[2],m_squares[3] };

	//Keep the current position in temporary variable.
	Position tempPos = m_position;

	//clean current place 
	clean(board);

	//Actually rotate.
	actRotate();

	//If the board in thie place isn't clean then restor the last squares 
	//kept in temp array and draw th shape again in the same place
	if (!isClean(board))
	{
		m_squares[0] = temp[0];
		m_squares[1] = temp[1];
		m_squares[2] = temp[2];
		m_squares[3] = temp[3];
		m_position = tempPos;
		draw(board);
		//Can't be rotated.
		return false;
	}

	//Draw the shape in the new place
	draw(board);

	//Rotation succeed.
	return true;
};
//==============================================================
void GameShape::actMove(Movement direction)
{
	switch (direction)
	{
	case right:
		for (int i = 0;i < NUM_OF_SQUARES;i++)
			m_squares[i].m_col += 1;
		break;
	case left:
		for (int i = 0;i < NUM_OF_SQUARES;i++)
			m_squares[i].m_col -= 1;
		break;
	case down:
		for (int i = 0;i < NUM_OF_SQUARES;i++)
			m_squares[i].m_row += 1;
	}
}
