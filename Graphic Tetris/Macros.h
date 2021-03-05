#pragma once
#include <SFML/Graphics.hpp>

//The size of every square on the game board
const int SQR_SIZE = 40;

//Number of rows of squares on the game board
const int ROWS = 20;

//Number of columns of squares on the game board
const int COLS = 20;

//The half of the columns number
const int MID = 8;

//Number os available shapes 
const int NUMBER_OF_SHAPES = 5;

//Number of available colors
const int NUMBER_OF_COLORS = 4;

//constant colors used in the game
const sf::Color BLUE = sf::Color::Cyan;
const sf::Color RED = sf::Color::Red;
const sf::Color YELLOW = sf::Color::Yellow;
const sf::Color GREEN = sf::Color::Green;
const sf::Color EMPTY = sf::Color::Blue;
const sf::Color BLACK = sf::Color::Black;

//Number of levels in the game
const int NUMBER_OF_LEVELS = 8;

//The width of the points bar 
const int POINTS_BAR_WIDTH = 100;