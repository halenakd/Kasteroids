#ifndef J1_SHAPE_H
#define J1_SHAPE_H

/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date November, 11, 2021.
* \version Feb, 6, 2022.
* \brief A Class to store a Geometrical Shape
**/

#include "point2.h"
#include "window.h"

class Shape 
{
	public:
		virtual void draw(Window &w)=0;
		virtual void addX(double dy)=0;
		virtual void addY(double dy)=0;
};

#endif
