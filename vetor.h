#ifndef __VETOR_H__
#define __VETOR_H__

/**
* \author Halena Kulmann Duarte
* \date Feb, 6, 2022.
* \version Feb, 11, 2022.
**/

#include "point2.h"
#include "window.h"
#include <cmath>
#include <iostream>
using namespace std;

class Vetor
{
    public:
        Point2 pv;
        Vetor();
        Vetor(Point2 p1, Point2 p2);
        Vetor(double x1, double y1, double x2, double y2);
        Vetor(Point2 p1);
        Vetor(double x, double y);
        Vetor operator+(Vetor v2);
        Vetor operator-(Vetor v2);
        Vetor operator*(double num);
        double operator*(Vetor v2);
        double modulo();
        double angulo(Vetor v2);
        Vetor normalizar();
        void drawv(Point2 o, Window &w);
};


#endif