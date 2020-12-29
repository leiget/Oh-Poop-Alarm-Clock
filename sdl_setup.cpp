/*
    Has all the functions that relate to the init and quitting of SDL.

    Copyright James Russell 2010
*/

//INCLUDES//
#include "sdl_setup.h"

////////////////FUNCTIONS////////////////
//Start SDL.//
bool AC_StartSDL(void)
{
    //Say you're starting SDL.
    printf("\nStarting SDL.\n");

    //Start SDL video, audio, and timer.
    //If it failed...
    if(SDL_Init(AC_SDL_InitFlags)==-1)
    {
        //Say so and why.
        printf("***SDL failed to init: %s***\n",SDL_GetError());
        //Return 1 for SDL_Init fail.
        return false;
    }

    //Otherwise, it must of been init.
    //Say that SDL was initalized.
    printf("SDL initalized.\n");

    //Return true for success.
    return true;
}
//Quit SDL.//
void AC_QuitSDL(void)
{
    if(SDL_WasInit(AC_SDL_InitFlags)==AC_SDL_InitFlags)
    {
        //Just quit SDL.
        SDL_Quit();
    }

    //Say SDL was closed.
    printf("SDL closed.\n");
}

////////////////EOF////////////////
