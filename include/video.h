/*
    File contains all functions for blitting to screen, and anything else related to video usage
        in SDL.

    AC_ShowSurface function based off function from LazyFoo at lazyfoo.net.

    Copyright James Russell 2010
*/

//If video.h is not defined already,
//  define it now.
#ifndef VIDEO_H
#define VIDEO_H

//INCDLUES//
//Local//
#include "main.h"

////////////////FUNCTIONS////////////////
//Setup video.//
bool AC_SetupVideo(void);
//Show surface.
void AC_ShowSurface(SDL_Surface *AC_ShowSurfSrc, int x, int y);

//End preprocessor if at top of file.
#endif
