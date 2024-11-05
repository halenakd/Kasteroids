#ifndef J1_CIRCLE_H
#define J1_CIRCLE_H

/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date Dec, 2021.
**/

#include "point2.h"
#include "window.h"
#include "shape.h"

class Circle: public Shape
{
    public:
        unsigned int n; 
        double raio;
        Point2 centro;
        Point2 *p;
        Circle();
        Circle(unsigned n, double raio, Point2 centro);
        void mover(double dx, double dy);
        void addX(double dx);
        void addY(double dy);
        void draw(Window &w);
};

#endif