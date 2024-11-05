/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date Feb, 10, 2022.
**/

#include "objeto.h"
#include <cmath>

// construtor para inicializar o objeto
Objeto::Objeto():
    inicial{0.0, 0.0}, np{0}, p{nullptr}, u{nullptr}, ang{0},
        tx{0}, ty{0}, sx{1.0}, sy{1.0}, vx{0}, vy{0}, ax{0}, ay{0}, t{0}
{}

// construtor da nave
Objeto::Objeto(Point2 inicial, size_t np): Objeto()
{
    // p - pontos iniciais, u - pontos transformados
    Objeto::np = np;
    p = new Point2[np];
    u = new Point2[np];

    // ângulo da nave
    ang = 0;

    // posição inicial antes de transladar
    tx = inicial.x, ty = inicial.y;

    // escala
    sx = 1, sy = 1;

    // acelereção
    t = 0;
    ax = 0, ay = 0;

    // velocidade
    vx = 0, vy = 0; 

    transformar();
}

// destrutor da nave
Objeto::~Objeto()
{
    if(p == nullptr)
    {
        delete[] p;
        p = nullptr;
    }
    if(u == nullptr)
    {
        delete[] u;
        u = nullptr;
    }
}

// atualiza o ângulo de rotação da nave e faz ela rotacionar
void Objeto::angulo(double angrot)
{
    Objeto::ang += angrot;
    transformar();
}

// movimenta a nave na direção em que está sendo acelerada e faz o decaimento gradual da aceleração
// nave continua em movimento mesmo depois de parar de apertar o botão
void Objeto::mover(double dt)
{
    // velocidade
    Objeto::vx = vx + ax * dt;
    Objeto::vy = vy + ay * dt;

    // translação
    Objeto::tx += vx * dt;
    Objeto::ty += vy * dt;
    transformar();

    // acelereção e decaimento
    ax = ax * exp((1-t)/20.0);
    ay = ay * exp((1-t)/20.0);
    t = t + dt;
}

// acelera a nave
void Objeto::acelerar(double a) 
{
    t = 1;
    ax += a * cos(ang);
    ay += a * sin(ang);
}

// faz a escala, a rotação e a translação da nave
void Objeto::transformar() 
{
    // translação, rotação, escala
    for(unsigned int i = 0; i < np; i++) 
    {
        u[i].x = p[i].x * sx * cos(ang) - p[i].y * sy * sin(ang) + tx;
        u[i].y = p[i].x * sx * sin(ang) + p[i].y * sy * cos(ang) + ty;
    }
}