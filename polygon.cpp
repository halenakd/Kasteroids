/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date November, 11, 2021.
* \version Feb, 6, 2022.
* \brief A Class to store a Geometrical Shape
**/

#include "polygon.h"
#include <iostream>
using namespace std;

// construtor vazio
Polygon::Polygon():
	p{nullptr}, n{0}
{}

// construtor 
Polygon::Polygon(int n, Point2 p[]):
    n{n}
{
    Polygon::p=new Point2[n];
    for(int i = 0; i < n; i++)
	    Polygon::p[i] = p[i];
}

// destrutor
Polygon::~Polygon()
{
    delete[] p;
    p = nullptr;
}

// adiciona/subtrai o eixo x
void Polygon::addX(double dx)
{
    for(int i = 0; i < n; i++)
	    Polygon::p[i].x+=dx;
}

// adiciona/subtrai o eixo y
void Polygon::addY(double dy)
{
    for(int i = 0; i < n; i++)
		Polygon::p[i].y+=dy;
}

// desenha o polígono
void Polygon::draw(Window &w)
{
    for(int i = 0; i < n - 1; i++) {
        w.drawLine(p[i], p[i + 1]);
    }
    w.drawLine(p[n -1], p[0]);
}