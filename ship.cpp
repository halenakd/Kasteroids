/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date Feb, 8, 2022.
* \version Feb, 10, 2022.
**/

#include "ship.h"
#include <cmath>

// construtor da nave
Ship::Ship(Point2 inicial):
    Objeto(inicial, 3)
{
    // pontos iniciais
    p[0] = Point2(30*cos(0.0/1.0*2*M_PI), 30*sin(0.0/1.0*2*M_PI));
    p[1] = Point2(20*cos(1.0/3.0*2*M_PI), 20*sin(1.0/3.0*2*M_PI));
    p[2] = Point2(20*cos(-1.0/3.0*2*M_PI), 20*sin(-1.0/3.0*2*M_PI));
    transformar();
}

// destrutor da nave
Ship::~Ship()
{}

// desenha a nave e seu vetor
void Ship::draw(Window &w)
{
    for(int i = 0; i < 3 - 1; i++)
    {
        w.drawLine(u[i], u[i + 1]);
    }
    w.drawLine(u[3 - 1], u[0]);
}

// colisao da nave com asteroid
bool Ship::colisao(Asteroid *a1)
{ 
    for(int i = 0; i < 2; i++)
    {
        // vetor direção da reta
        Vetor direcao(u[i].x, u[i].y, u[(i+1)%4].x, u[(i+1)%4].y);
        // vetor do começo da reta ao ponto(centro asteroid)
        Vetor retaponto(u[i].x, u[i].y, a1->tx, a1->ty);
        // módulo do vetor direção
        double mod = direcao.modulo();
        // vetor unitário da direção
        Vetor unit = direcao.normalizar();
        // projeção escalar
        double projE = (direcao.pv.x * retaponto.pv.x + direcao.pv.y * retaponto.pv.y) / mod;
        // projeção vetorial = projeção escalar * vetor unitário da direção
        double projVx = projE * unit.pv.x;   
        double projVy = projE * unit.pv.y;
        // vetor da da reta à projeção
        Vetor projv(u[i], Point2(u[i].x + projVx, u[i].y + projVy));
        // vetor da reta 
        Vetor retapponto(u[i], Point2(u[i].x + retaponto.pv.x, u[i].y + retaponto.pv.y));
        // complemento ortogonal, co + projV = retaponto
        double coX = retaponto.pv.x - projVx;
        double coY = retaponto.pv.y - projVy;
        // vetor complemento ortogonal
        Vetor co(Point2(u[i].x + projVx, u[i].y + projVy), Point2(u[i].x + projVx + coX, u[i].y + projVy + coY));
        // módulo do vetor complemento ortogonal
        double modco = co.modulo();
        // colisão ou não
        double te = 0;
        if(direcao.pv.x!=0) {
            te = (projVx)/direcao.pv.x;
        }
        else {
            te = (projVy)/direcao.pv.y;
        }
        bool col = te>=0 && te<=1 && modco <= a1->raio;
        return col;
    }
    return false;
}
