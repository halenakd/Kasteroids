#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

/**
* \author Halena Kulmann Duarte
* \date Feb, 8, 2022.
* \version Feb, 11, 2022.
**/

#include "point2.h"
#include "window.h"
#include "objeto.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>


class Projectile: public Objeto
{
    public:
        double raio;
        Projectile(Point2 ponta, double ang);
        ~Projectile();
        void bolinha();
        bool foraJanela(int largura, int altura);
        virtual void draw(Window &w);
};
#endif