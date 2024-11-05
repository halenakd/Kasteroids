#ifndef J1_POLYGON_H
#define J1_POLYGON_H

/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date November, 11, 2021.
* \version Feb, 6, 2022.
* \brief A Class to store a Geometrical Shape
**/

#include "point2.h"
#include "window.h"
#include "shape.h"

class Polygon: public Shape
{
    public:
        Polygon();
        Polygon(int n, Point2 p[]);
        void addX(double dx);
        void addY(double dy);
        void draw(Window &w);
        ~Polygon();
        Point2 *p;
        int n;
};
#endif