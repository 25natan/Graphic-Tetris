//==============================================================
//This shape's squares arr in this order:
//                    *
//                  * * *
//And the indexes in the cells array are in match:
//                    0
//                  1 2 3
//This shape can be rotated into these positions:
//
//    *     1     
//    * *   2 0
//    *     3
//
//     * * *   3 2 1
//       *       0
//
//       *       3
//     * *     0 2
//       *       1
//==============================================================
#pragma once
#include "GameShape.h"

class Shape1 :public GameShape {
public:
	Shape1(int, int, sf::Color, Board&);
private:
	void actRotate();
};