/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date November, 11, 2021.
* \version Feb, 6, 2022.
* \brief The triangle constructor
* \param p the points that describe the triangle, the points will be COPIED.
**/

#include "triangle.h"

// construtor
Triangle::Triangle(Point2 p[]):
	Polygon(3, p)
{}