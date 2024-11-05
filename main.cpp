/**
* \author Éder Augusto Penharbel, Halena Kulmann Duarte
* \date November, 11, 2021.
* \version Feb, 11, 2022.
**/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
#include "window.h"
#include "sdl.h"
#include "quadrilateral.h"
#include "triangle.h"
#include "circle.h"
#include "vetor.h"
#include "ship.h"
#include "asteroid.h"
#include "projectile.h"

int main(int argc, char *argv[])
{
    SDL sdl;
    sdl.init();    
    bool quit = false;
    
    // ---- VARIÁVEIS GLOBAIS ----
    const int LARGURA_JANELA = 800;
    const int ALTURA_JANELA = 600;
    const double dt = 1/10.0;
    srand(time(0));

    // ---- CONSTRUTORES ----
    // nave no ponto inicial (400, 300)
    Ship nave(Point2(400, 300));

    // vector das balas
    vector <Projectile*> projectiles;

    // vector dos asteroids
    vector <Asteroid*> asteroids;
    vector <Asteroid*>::iterator it;

    // ---- EVENTOS DO JOGO ----
	//Event handler
	SDL_Event e;
    {
        Window w(LARGURA_JANELA, ALTURA_JANELA);
        // Loop de Jogo
        while (!quit) 
        {
            // ---- FILA ----
            while(SDL_PollEvent(&e) != 0)
            {
                // User requests quit
                if(e.type == SDL_QUIT)
                {
                    quit = true;
                }

                // ---- TECLAS ----
                if (e.type == SDL_KEYDOWN) 
                {
                    // para esquerda
                    if (e.key.keysym.sym == SDLK_LEFT) 
                    {
                        // gira a nave em sentido anti-horário
                        nave.angulo(-M_PI/18.0);
                    }
                    // para direita
                    if (e.key.keysym.sym == SDLK_RIGHT) 
                    {
                        // gira a nave em sentido horário
                        nave.angulo(+M_PI/18.0);
                    }
                    // para cima
                    if (e.key.keysym.sym == SDLK_UP) 
                    {
                        // movimenta a nave na direção em que está apontada
                        nave.acelerar(+1.0/10.0);
                    }
                    // para baixo
                    if (e.key.keysym.sym == SDLK_DOWN) 
                    {
                        // reaparece/translada a nave em ponto aleatório
                        nave.tx = 50+rand()%750;
                        nave.ty = 50+rand()%550;
                    }
                    // espaço
                    if (e.key.keysym.sym == SDLK_SPACE) 
                    {
                        // cria uma bala e coloca no vector
                        Projectile* pr1 = new Projectile(nave.u[0], nave.ang);
                        projectiles.push_back(pr1);
                    }
                }
            }

            // clear surface
            w.clear();

            //desenha a nave
            nave.draw(w);

            // continua movendo a nave
            nave.mover(1.0/85.0);

            // desenha e movimenta as balas
            for (size_t i = 0; i < projectiles.size(); i++)
            {
                projectiles[i]->mover(dt);
                projectiles[i]->draw(w);
                // deleta as balas se estiverem fora da janela
                if(projectiles[i]->foraJanela(800, 600))
                {
                    projectiles[i]->~Projectile();
                    projectiles.erase(projectiles.begin()+i);
                }
            }

            // cria os asteroids e coloca no vector
            if(rand() % 18000 == 0)
            {
                Asteroid* a1 = new Asteroid(25.0);
                asteroids.push_back(a1);
            }


            // colisao das balas com os asteroids
            bool colProjAst = false;
            for(size_t i = 0; i < projectiles.size(); i++)
            {
                for(size_t j = 0; j < asteroids.size(); j++)
                {
                    if(!colProjAst)
                    {
                        Projectile * newProj = projectiles[i];
                        Asteroid * newAst = asteroids[j];
                        // calcula a distância do centro da bala até o centro do asteroid
                        double d = sqrt(pow((newAst->tx - newProj->tx), 2.0) + pow((newAst->ty - newProj->ty), 2.0));
                        // se a distância for menor ou igual do que a soma dos dois raios = colisão
                        if((newAst->raio+newProj->raio)>=d)
                        {
                            // deleta a bala
                            projectiles[i]->~Projectile();
                            projectiles.erase(projectiles.begin()+i);

                            // se for um asteroid grande, cria mais 2 médios
                            if(newAst->raio == 25.0)
                            {
                                Asteroid* a2 = new Asteroid(18.0, Point2((newAst->tx)-20, (newAst->ty)+20));
                                asteroids.push_back(a2);
                                Asteroid* a3 = new Asteroid(18.0, Point2((newAst->tx)+20, (newAst->ty)-20));
                                asteroids.push_back(a3);
                            }

                            // se for um asteroid médio, cria mais 2 pequenos

                            if(newAst->raio == 18.0)
                            {
                                Asteroid* a4 = new Asteroid(11.0, Point2((newAst->tx)-15, (newAst->ty)+15));
                                asteroids.push_back(a4);
                                Asteroid* a5 = new Asteroid(11.0, Point2((newAst->tx)+15, (newAst->ty)-15));
                                asteroids.push_back(a5);
                            }

                            colProjAst = true;

                            // deleta o asteroid
                            asteroids[j]->~Asteroid();
                            asteroids.erase(asteroids.begin()+j);
                        }
                    }
                }
            }

            // movimenta e desenha os asteroids
            for(size_t i = 0; i < asteroids.size(); i++)
            {
                asteroids[i]->mover(dt);
                asteroids[i]->draw(w);
            }

            // colisao da nave com os asteroids
            bool colNavAst = false;
            for(size_t i = 0; i < asteroids.size(); i++)
            {
                if(!colNavAst)
                {
                    Asteroid * newAst = asteroids[i];
                    // se colidir, o jogo acaba
                    if(nave.colisao(newAst))
                    {
                        cout<<"GAMEOVER"<<endl;
                        sdl.quit();
                        return 0;
                    }
                }
            }

            // update renderer
            w.update();
        }
        // Fim do loop de jogo
    }
    sdl.quit();
    return 0;
}
