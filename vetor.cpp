/**
* \author Halena Kulmann Duarte
* \date Feb, 6, 2022.
* \version Feb, 11, 2022.
**/

#include "vetor.h"

// vetor
Vetor::Vetor():
    pv{Point2()}
{}

// vetor dos pontos p1 ao p2
Vetor::Vetor(Point2 p1, Point2 p2)
{
    pv = Point2(p2.x - p1.x, p2.y - p1.y);
}

// vetor de (x1, y1) a (x2, y2)
Vetor::Vetor(double x1, double y1, double x2, double y2) 
{
    pv = Point2(x2 - x1, y2 - y1);
}

// vetor do ponto p1
Vetor::Vetor(Point2 p1)
{
    pv = p1;
}

// vetor de (x, y)
Vetor::Vetor(double x, double y)
{
    pv = Point2(x, y);
}

// soma do vetor1 com o vetor2, resultando no vetor3
Vetor Vetor::operator+(Vetor v2) 
{
    Vetor v1(pv), v3;
    v3.pv.x = v1.pv.x + v2.pv.x;
    v3.pv.y = v1.pv.y + v2.pv.y;
    return v3;
}

// subtração do vetor2 do vetor1, resultando no vetor3
Vetor Vetor::operator-(Vetor v2) 
{
    Vetor v1(pv), v3;
    v3.pv.x = v1.pv.x - v2.pv.x;
    v3.pv.y = v1.pv.y - v2.pv.y;
    return v3;
}

// vetor multiplicado por um escalar(um número)
Vetor Vetor::operator*(double num) 
{
    Vetor v1(pv), v2;
    v2.pv.x = v1.pv.x * num;
    v2.pv.y = v1.pv.y * num;
    return v2;
}

// produto escalar do vetor1 e vetor2
// se = 0, perpendiculares
double Vetor::operator*(Vetor v2) 
{
    Vetor v1(pv);
    double escalar = (v1.pv.x * v2.pv.x) + (v1.pv.y * v2.pv.y);
    return escalar;
}

// módulo do vetor1
double Vetor::modulo()
{
    double modulo = sqrt(pv.x * pv.x + pv.y * pv.y);
    return modulo;
}

// angulo do vetor1 em relação ao vetor2
double Vetor::angulo(Vetor v2) 
{
    Vetor v1(pv);
    double arccos = acos((v1 * v2) / (v1.modulo() * v2.modulo()));
    //double angulo = arccos*(180/M_PI);
    return arccos;
}

// normaliza o vetor, vetor unitário
Vetor Vetor::normalizar()
{
    Vetor v1(pv), v2;
    v2.pv.x = v1.pv.x/v1.modulo();
    v2.pv.y = v1.pv.y/v1.modulo();
    return v2;
}

// desenho da seta de um vetor a partir do ponto de origem
void Vetor::drawv(Point2 origem, Window &w)
{
    // corpo da seta
    Point2 p1(origem.x + pv.x, origem.y + pv.y);
    w.drawLine(origem, p1);
    // pontas
    double tam = sqrt(pow((p1.x-origem.x), 2) + pow((p1.y-origem.y), 2));
    double tamPonta = 0.2 * tam;
    double ang = atan2(p1.y-origem.y, p1.x-origem.x);
    // ponta 1
    double tmpY = p1.y + tamPonta * sin((3.0/4.0) * M_PI + ang); 
    double tmpX = p1.x + tamPonta * cos((3.0/4.0) * M_PI + ang);
    w.drawLine(p1.x, p1.y, tmpX, tmpY);
    // ponta 2
    tmpY = p1.y + tamPonta * sin((5.0/4.0) * M_PI + ang); 
    tmpX = p1.x + tamPonta * cos((5.0/4.0) * M_PI + ang); 
    w.drawLine(p1.x, p1.y, tmpX, tmpY);
}