//==============================================================
//This shape's squares arr in this order:
//                  *
//                  * * *
//And the indexes in the cells array are:
//                  0
//                  1 2 3
//This shape can be rotated in to these positions:
//       * *  1 0
//       *    2
//	     *    3
//
//     * * *    3 2 1
//         *        0
//
//       *    3
//       *    2
//     * *  0 1
//
//==============================================================

#pragma once
#include "GameShape.h"





class Shape2 :public GameShape {
public:
	Shape2(int, int, sf::Color, Board&);
private:
	void actRotate();
};