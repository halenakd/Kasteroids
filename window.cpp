/**
* \author Éder Augusto Penharbel
* \date November, 11, 2021.
**/

#include "window.h"
#include "point2.h"
#include <iostream>
using namespace std;

Window::Window(int width, int height):
    width{width},
    height{height}
{
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
    if (window == NULL)
    {
        cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        exit(1);
    }
	//Create renderer for window
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Window::~Window()
{
	//Destroy window
	SDL_DestroyWindow(window);
}

void Window::drawLine(int xi, int yi, int xf, int yf)
{
    //Draw blue horizontal line
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);		
    SDL_RenderDrawLine(renderer, xi, yi, xf, yf);
}
    
void Window::drawLine(Point2 pi, Point2 pf)
{
    drawLine(pi.x, pi.y, pf.x, pf.y);
}

void Window::clear()
{
    //Clear screen
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);
}

void Window::update()
{
	//Update screen
    SDL_RenderPresent(renderer);
}
