#ifndef J1_QUADRILATERAL_H
#define J1_QUADRILATERAL_H

/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date November, 11, 2021.
* \version Feb, 6, 2022.
* \brief A class to store a Quadrilateral 
**/

#include "point2.h"
#include "window.h"
#include "polygon.h"

class Quadrilateral: public Polygon 
{
    public:
		Quadrilateral(Point2 p[]);
};

#endif
