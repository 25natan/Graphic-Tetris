# Graphic-Tetris
Tetris Game

Debug and run instructions:
To run and debug this project you need to have visual studio 2019 
instaled on your computer and you need to have the SFML version 2.5.1 match
to your computer, you can download it from https://www.sfml-dev.org/download/sfml/2.5.1/.
When you have these you can just download the project and open it in visual studio
and direct it to the include and source files of SFML as shown at https://www.sfml-dev.org/tutorials/2.5/start-vc.php
If you set everything right youcan run it and engoy playing/editing as you wish.

OOD - overview:
The main board of the game is implemented in a 
class Board defined in Board.h and uses sfml rectangles
for the game squares.
The shapes in the game has a base class GameShape which points 
to some squares on the board and can be moved or rotated.
The spesific shapes are defined in the files Shape1.h Shape2.h ...
The player info is implemented in a class PlayerPoints which 
contains the points info and its drawble shape.
The main menu is implemented in a class Menu which
shows the menu and get the user choosen level.
The main controller of the game which actually manage the game proccess
is implemented in a class GameController defined in file GameController.h
and uses all the game classes to maintain the game proccess.
