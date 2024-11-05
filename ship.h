#ifndef __SHIP_H__
#define __SHIP_H__

/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date Feb, 8, 2022.
* \version Feb, 10, 2022.
**/

#include "objeto.h"
#include "asteroid.h"
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

class Ship: public Objeto
{
    public:
        Ship(Point2 inicial);
        ~Ship();
        virtual void draw(Window &w);
        bool colisao(Asteroid *a1);
};

#endif