/**
* \author Éder Augusto Penharbel
* \date November, 11, 2021.
**/

#include <SDL2/SDL.h>
#include "sdl.h"
#include <iostream>
using namespace std;

SDL::SDL()
{
}

bool SDL::init()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        exit(1);
        return false;
	}
    return true;
}

bool SDL::quit()
{
	//Quit SDL subsystems
	SDL_Quit();
    return true;
}
