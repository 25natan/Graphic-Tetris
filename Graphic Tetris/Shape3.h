#pragma once
#include "GameShape.h"
//
//This shape's squares arr in this order:
//                                * *
//                                * *
//Rotation has no effect on this shape

class Shape3 :public GameShape {
public:
	Shape3(int, int, sf::Color, Board&);
private:
	void actRotate() {}
};