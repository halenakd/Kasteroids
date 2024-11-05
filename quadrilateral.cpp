/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date November, 11, 2021.
* \version Feb, 6, 2022.
* \brief The quadrilateral constructor
* \param p the points that describe the quadrilateral, the points will be COPIED.
**/

#include "quadrilateral.h"

// construtor
Quadrilateral::Quadrilateral(Point2 p[]):
    Polygon(4, p)
{}