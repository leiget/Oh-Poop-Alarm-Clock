/*
    Has all the functions that relate to the init and quitting of SDL.

    Copyright James Russell 2010
*/

//If sdl_setup.h was not included before,
//  include it now.
#ifndef SDL_SETUP_H
#define SDL_SETUP_H

//INCLUDES//
//System//
#include "main.h"

////////////////FUNCTIONS////////////////
//Start SDL.//
bool AC_StartSDL(void);
//Quit SDL.//
void AC_QuitSDL(void);

//End preprocessor if at top of file.
#endif
