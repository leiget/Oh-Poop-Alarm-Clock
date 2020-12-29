/*
    Contains all the things needed to use events in SDL.

    Copyright James Russell 2010
*/

//If event.h was not already declared,
//  declare it now.
#ifndef EVENT_H
#define EVENT_H

//INCLUDES//
#include "main.h"

//CLASS_DECLARES//
//Main event. Don't know if I need more than one.
extern SDL_Event AC_MainEvent;

////////////////FUNCTIONS////////////////
//Check all the input.
void AC_CheckInput(void);
//Check the mouse input.
void AC_CheckMouseInput(void);
//Check the input for the "Set Time" arrows.
void AC_CheckSetTimeArrowInput(void);

//End preprocessor if at top of file.
#endif
