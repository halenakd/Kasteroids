#ifndef __OBJETO_H__
#define __OBJETO_H__

/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date Feb, 10, 2022.
**/

#include "window.h"
#include "vetor.h"
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

class Objeto
{
    public:
        Point2 inicial;
        size_t np;
        Point2 * p;
        Point2 * u;
        double ang;
        double tx, ty;
        double sx, sy;
        double vx, vy;
        double ax, ay;
        double t;
        Objeto();
        Objeto(Point2 inicial, size_t np);
        virtual ~Objeto() = 0;
        virtual void draw(Window &w) = 0;
        virtual void angulo(double angrot);
        virtual void mover(double dt);
        virtual void acelerar(double a);
        virtual void transformar(); // translação, rotação e escala
};

#endif