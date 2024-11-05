/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date Dec, 2021.
**/

#include "circle.h"
#include <cmath>

Circle::Circle()
{}

// construção do circulo
Circle::Circle(unsigned n, double raio, Point2 centro):
    n{n}, raio{raio}, centro{centro}
{
    Circle::p = new Point2[n];
    double a = 0;
    double inca = 2 * M_PI / n;
    for(unsigned int i = 0; i < n; i++)
    {
        Circle::p[i].x = centro.x + cos(a) * raio;
        Circle::p[i].y = centro.y + sin(a) * raio;
        a += inca;
    }
}

// adição e subtração no eixo x
void Circle::addX(double dx)
{
    for (unsigned int i = 0; i < n; i++)
		p[i].x += dx;
        centro.x += dx;
}

// adição e subtração no eixo y
void Circle::addY(double dy)
{
    for (unsigned int i = 0; i < n; i++)
		p[i].y += dy;
        centro.y += dy;
}

// movimentação do circulo
void Circle::mover(double dx, double dy)
{
    addX(dx);
    addY(dy);
    centro.x += dx;
    centro.y += dy;
}

// desenho do circulo
void Circle::draw(Window &w)
{
    for(unsigned int i=0; i<n-1; i++)
        w.drawLine(p[i], p[i+1]);
    w.drawLine(p[n-1], p[0]);
}