#ifndef __ASTEROID_H__
#define __ASTEROID_H__

/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date November, 10, 2021.
**/

#include "point2.h"
#include "window.h"
#include "objeto.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

class Asteroid: public Objeto
{
    public:
        double raio;
        Point2 astPai;
        Asteroid(double raio);
        Asteroid(double raio, Point2 astPai);
        ~Asteroid();
        void bolinha();
        virtual void draw(Window &w);
};

#endif