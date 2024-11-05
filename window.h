#ifndef J1_WINDOW_H
#define J1_WINDOW_H

/**
* \author Éder Augusto Penharbel
* \date November, 11, 2021.
**/

#include <SDL2/SDL.h>
#include "point2.h"

class Window 
{
    protected:
        int width;
        int height;
	    //The window we'll be rendering to
    	SDL_Window * window;
        //The window renderer
        SDL_Renderer * renderer = NULL;
    public:
        Window(int width, int height);
        ~Window();

        void drawLine(int xi, int yi, int xf, int yf);
        void drawLine(Point2 pi, Point2 pf);
        void clear();
        void update();
};

#endif
