#ifndef J1_TRIANGLE_H
#define J1_TRIANGLE_H

/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date November, 11, 2021.
* \version Feb, 6, 2022.
* \brief A Class to store a Triangle Shape
**/

#include "point2.h"
#include "window.h"
#include "polygon.h"

class Triangle: public Polygon 
{
    public:
		Triangle(Point2 p[]);
};

#endif