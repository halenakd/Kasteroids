/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date November, 10, 2021.
**/

#include "asteroid.h"

// construtor do asteroid
Asteroid::Asteroid(double raio):
    Objeto(Point2(), 30), raio{raio}
{
    // posição inicial aleatória
    srand(time(0));
    tx = 30+rand()%770;
    ty = 30+rand()%570;
    // velocidade
    vx = 1/80.0 * cos(ang);
    vy = 1/80.0 * sin(ang);
    // cria o formato
    bolinha();
    // movimenta
    transformar();
}

// construtor de um asteroid a partir da posição de outro
Asteroid::Asteroid(double raio, Point2 astPai):
    Objeto(Point2(), 30), raio{raio}, astPai{astPai}
{
    // posição inicial aleatória
    srand(time(0));
    tx = astPai.x;
    ty = astPai.y;
    // velocidade
    vx = 1/80.0 * cos(ang);
    vy = 1/80.0 * sin(ang);
    // cria o formato
    bolinha();
    // movimenta
    transformar();
}

// destrutor
Asteroid::~Asteroid()
{}

// cria o formato de circulo para o asteroid
void Asteroid::bolinha() 
{
    double a = 0;
    double inca = 2 * M_PI / np;
    for(unsigned int i = 0; i < np; i++)
    {
        p[i] = Point2(cos(a) * raio, sin(a) * raio);
        a += inca;
    }
}  

// desenha o asteroid
void Asteroid::draw(Window &w)
{
    for(unsigned int i=0; i<np-1; i++)
        w.drawLine(u[i], u[i+1]);
    w.drawLine(u[np-1], u[0]);
}