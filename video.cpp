/*
    File contains all functions for blitting to screen, and anything else related to video usage
        in SDL.

    AC_ShowSurface function based off function from LazyFoo at lazyfoo.net.

    Copyright James Russell 2010
*/

//INCLUDES//
#include "video.h"

//External Definitions//
extern SDL_Surface *AC_Screen;
extern void AC_SetWindowCaption(void);

////////////////FUNCTIONS////////////////
//Setup video.//
bool AC_SetupVideo(void)
{
    //////  ADDED by Gary /////
    //Icon, Load the icon into memory, SDL_WM_SetIcon().
    SDL_WM_SetIcon(SDL_LoadBMP("docs/icon.bmp"),NULL);

    //Say you are setting up video.
    printf("\nSetting up video...\n");

    //Setup the video.
    AC_Screen=SDL_SetVideoMode(AC_Screen_Width,AC_Screen_Height,AC_Screen_BPP,AC_Screen_Flags);

    //If the video was not set...
    if(AC_Screen==NULL)
    {
        //Say so and why.
        printf("***The video was not set: %s***\n",SDL_GetError());
        //return false for fail.
        return false;
    }

    //Set caption and icon name.
    AC_SetWindowCaption();

    //Otherwise, it must of succeded.
    //Say so.
    printf("Video setup.\n");

    //Display the video info.
    //First, the working width, height, and bpp.
    printf("Width=%d,Height=%d,BPP=%d\n",AC_Screen->w,AC_Screen->h,AC_Screen->format->BitsPerPixel);

    //Return true for success.
    return true;
}
//Show surface.
void AC_ShowSurface(SDL_Surface *AC_ShowSurfSrc,int x,int y)
{
    //Temp rect for offset keeping.
    SDL_Rect offset;
    //Set the x and y position.
    offset.x=x;
    offset.y=y;
    //Blit the surface to the main screen surface.
    SDL_BlitSurface(AC_ShowSurfSrc,NULL,AC_Screen,&offset);
}

////////////////EOF////////////////
