/*
    Contains all functions, variables, etc. that are related to the functionality of SDL_ttf.

    Copyright James Russell 2010
*/

//INCLUDES//
#include "ttf.h"

////////////////FUNCTIONS////////////////
//Initalize SDL_ttf.//
bool AC_InitTTF(void)
{
    //Say you're starting the TTF functionality.
    printf("\nStarting SDL_ttf.\n");

    //Initalize SDL_ttf.
    //If it fails...
    if(TTF_Init()==-1)
    {
        //Say so and why.
        printf("***SDL_ttf failed to init: %s***\n",TTF_GetError());
        //Return false for TTF_Init fail.
        return false;
    }

    //Otherwise, it must of been successful.
    //Say so.
    printf("SDL_ttf initalized.\n");

    //Return true for success.
    return true;
}
//Quit SDL_ttf.//
void AC_QuitTTF(void)
{
    //Check to see if SDL_ttf was initalized.
    //If it was...
    if(TTF_WasInit())
    {
        //Shutdown SDL_ttf.
        TTF_Quit();
    }

    //See if it was shuwdown.
    //If it was...
    if(!TTF_WasInit())
    {
        //Say it was shuwdown.
        printf("SDL_ttf shutdown.\n");
    }
    //Otherwise, it must of failed to shutdown.
    else
    {
        //Say so.
        printf("***SDL_ttf is still running.***\n");
    }
}

////////////////EOF////////////////
