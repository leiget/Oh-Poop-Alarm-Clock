/*
    Contains all functions, variables, etc. that are related to the functionality of SDL_ttf.

    Copyright James Russell 2010
*/

//If ttf.h was not included before,
//  include it now.
#ifndef TTF_H
#define TTF_H

//INCLUDES//
#include "main.h"

////////////////FUNCTIONS////////////////
//Initalize SDL_ttf.//
bool AC_InitTTF(void);
//Quit SDL_ttf.//
void AC_QuitTTF(void);

//End preproccessor if at top of file.
#endif
