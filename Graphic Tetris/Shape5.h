#pragma once
#include "GameShape.h"

//This shape's squares arr in this order:
//                                *      0
//                              * *    1 2
//                              *      3
//This shape can be rotated in to this position:
//                                 * *
//                                   * *
  
class Shape5 :public GameShape {
public:
	Shape5(int, int, sf::Color, Board&);
private:
	void actRotate();
};