#pragma once
#include "GameShape.h"
//
//This shape's squares arr in this order:
//                                *  0
//                                *  1
//                                *  2
//                                *  3
//This shape can be rotated into this position:
//
//                                * * * *

class Shape4 :public GameShape {
public:
	Shape4(int, int, sf::Color, Board&);
private:
	void actRotate();
};