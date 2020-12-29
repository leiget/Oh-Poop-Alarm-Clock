/*
    Contains all functions and info for window managment.

    Copyright James Russell 2010
*/

//INCLUDES//
#include "wm.h"

////////////////FUNCTIONS////////////////
//Set the caption and icon name.
void AC_SetWindowCaption(void)
{
    //Just set the caption and icon name.
    //Do I even need my own function for this?
    SDL_WM_SetCaption(AC_WindowCaption,AC_WindowIconName);
}

////////////////EOF////////////////////
