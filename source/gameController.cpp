#include "../include/GameController.h"
//==============================================================
GameController::GameController()
{
	//Initial the window to be in the size of the board plus the
	//size of the points bar.
	m_window.create(sf::VideoMode(COLS * SQR_SIZE, ROWS * SQR_SIZE + POINTS_BAR_WIDTH), "Tetris game");
}
//==============================================================
void GameController::run()
{
	//start random function
	srand(time(NULL));

	while (true)
	{
		//Set the level by the returned value from the menu
		m_level = m_menu.run(m_window, m_event);
		if (m_level == -1)
			return;

		//Set the board to a new one
		m_board = Board();

		//Set the waiting time by the choosen level
		m_waitTime = m_maxWaitTime - m_level * m_levelsDifTime;

		//Set player points to zero
		m_playerPoints.set(0);

		while (true)
		{
			m_shape = randomShape();
			//Check if the shape's first location on board is clean
			//and if it's not, then the game is over.
			if (!m_shape->isClean(m_board))
				break;

			//Draw first time.
			m_shape->draw(m_board);

			//Play untill the shape can't move any more.
			do
			{
				display();
				userPlay();
			} while (m_window.isOpen() && m_shape->move(down, m_board));

			//Free memory of this shape.
			delete m_shape;
			if (!m_window.isOpen())
				return;
			removeFullRow();
		}
	}
}
//==============================================================
GameShape* GameController::randomShape()
{
	int shapeType = rand() % NUMBER_OF_SHAPES;
	switch (shapeType)
	{
	case 0:
		return new Shape1(0, MID, randomColor(), m_board);
	case 1:
		return new Shape2(0, MID, randomColor(), m_board);
	case 2:
		return new Shape3(0, MID, randomColor(), m_board);
	case 3:
		return new Shape4(0, MID, randomColor(), m_board);
	default:
		return new Shape5(0, MID, randomColor(), m_board);
	}
}
//==============================================================
sf::Color GameController::randomColor() const
{
	int shapeColor = rand() % NUMBER_OF_COLORS;
	switch (shapeColor)
	{
	case 0:
		return GREEN;
	case 1:
		return BLUE;
	case 2:
		return RED;
	default:
		return YELLOW;
	}
}
//==============================================================
void GameController::userPlay()
{
	sf::Clock clock;
    bool change;
	while (clock.getElapsedTime().asMilliseconds() < m_waitTime)
	{
		if (m_window.pollEvent(m_event))
			switch(m_event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				return;
			case sf::Event::KeyPressed:
				//flag to tell if some change happened
				change = false;
				switch (m_event.key.code)
				{
				case sf::Keyboard::Left:
					change = m_shape->move(left, m_board);
					break;
				case sf::Keyboard::Right:
					change = m_shape->move(right, m_board);
					break;
				case sf::Keyboard::Down:
					//move down as much as it possible
					change = m_shape->move(down, m_board);
					while (m_shape->move(down, m_board))
						;
					break;
				case sf::Keyboard::Up:
				case sf::Keyboard::Enter:
					change = m_shape->rotate(m_board);
					break;
                default:;
				}
				if (change)
					display();
                break;
            default:;
			}
	}
}
//==============================================================
void GameController::display()
{
	m_window.clear();
	m_board.draw(m_window);
	m_playerPoints.draw(m_window);
	m_window.display();
}
//==============================================================
void GameController::removeFullRow()
{
	for (int i = 0;i < ROWS;i++)
		if (m_board.isFullRow(i))
		{
			//if some row is full then delete it but stay in this row 
			//to check again because the all board went down one row
			m_board.cleanRow(i);
			display();
			i--;
			m_playerPoints.add(m_level * 10);
		}
}
//==============================================================