/**
* \author Halena Kulmann Duarte
* \date Feb, 8, 2022.
* \version Feb, 11, 2022.
**/

#include "projectile.h"

// cria a bala na posição da ponta da nave e utiliza o angulo em que ela está apontada para movimentação
Projectile::Projectile(Point2 ponta, double ang):
    Objeto(Point2(), 30)
{
    Projectile::ang = ang;
    raio = 2.5;
    tx = ponta.x;
    ty = ponta.y;
    vx = 1.0 * cos(ang);
    vy = 1.0 * sin(ang);
    bolinha();
    transformar();
}

// destrutor
Projectile::~Projectile()
{}

// cria o circulo da bala
void Projectile::bolinha() 
{
    double a = 0;
    double inca = 2 * M_PI / np;
    for(unsigned int i = 0; i < np; i++)
    {
        p[i] = Point2(cos(a) * raio, sin(a) * raio);
        a += inca;
    }
}

// detecta se a posição da bala está fora da janela
bool Projectile::foraJanela(int largura, int altura) 
{
    if (tx < -10 || tx > largura + 10 || ty < -10 || ty > altura + 10)
    {
        return true;
    }
    return false;
}

// desenha a bala
void Projectile::draw(Window &w) 
{
    for(unsigned i=0; i<np-1; i++)
        w.drawLine(u[i], u[i+1]);
    w.drawLine(u[np-1], u[0]);
}





