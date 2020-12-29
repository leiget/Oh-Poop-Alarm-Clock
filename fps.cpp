/*
    Frames per second counting class.

    FPS class based off what I was taught by LazyFoo's tutorials on lazyfoo.net.
    It isn't nessesarally the same. I didn't copy it, because I don't remember it all
        exactly.

    It also contains the credit and logo rendering functionality.

    Copyright 2010 James Russell
*/

//INCLUDES//
#include "fps.h"

//External definitions//
extern SDL_Surface *AC_FPSSurf;
extern TTF_Font *AC_Font_ArialBig;
extern void AC_ShowSurface(SDL_Surface *AC_ShowSurfSrc, int x, int y);

////////////////CLASS////////////////
//Init of FPS class.
AC_C_FPS::AC_C_FPS(void)
{
    //Init the variables.
    TimeLastChecked=SDL_GetTicks();
    FpsNumber=0;

    //Say you init the FPS class.
    printf("FPS class constructed.\n");
}
//Init what couln't when the class was contructed.
void AC_C_FPS::InitFPS(void)
{
    //Convert the actual FPS number into a string
    //  for the SDL_WM_SetCaption function, which needs a string.
    sprintf(FpsAsString,"%d",FpsNumber);
    //Render the text surface.
    AC_FPSSurf=TTF_RenderText_Solid(AC_Font_ArialBig,FpsAsString,AC_Color_LightGrey);

    //Render the credit surface as text.
    AC_CreditSurf=TTF_RenderText_Blended(AC_Font_ArialSmall,"A creation of Oh! Poop! Productions!",AC_Color_LightGrey);
    //If it failed...
    if(AC_CreditSurf==NULL)
    {
        //Say so and why.
        printf("***Error rendering credit surface: %s***\n",TTF_GetError());
    }
}
//Show the FPS.
void AC_C_FPS::ShowFPS(void)
{
    //If the user says to render the FPS...
    if(AC_RenderFPS==true)
    {
        //Then show the FPS surface.
        AC_ShowSurface(AC_FPSSurf,595-AC_FPSSurf->w/2,25);
        //Also show the logo...
        AC_ShowSurface(AC_Logo,490,25);
        //...and the credit surface.
        AC_ShowSurface(AC_CreditSurf,616-AC_CreditSurf->w,95);
    }
}
//Check how many milliseconds have passed since last time set.
void AC_C_FPS::CheckTime(Uint32 Milliseconds)
{
    //If 1 second has passed...
    if(SDL_GetTicks()>TimeLastChecked+Milliseconds)
    {
        //Free the old fps text surface.
        SDL_FreeSurface(AC_FPSSurf);
        //Convert the actual FPS number into a string
        //  for the SDL_WM_SetCaption function, which needs a string.
        sprintf(FpsAsString,"%d",FpsNumber);
        //Reset the FPS counter.
        FpsNumber=0;
        //Reset the time.
        SetTime();
        //Then render the number to the surface.
        AC_FPSSurf=TTF_RenderText_Solid(AC_Font_ArialBig,FpsAsString,AC_Color_LightGrey);
    }
}
//Set the current time to compare to.
void AC_C_FPS::SetTime(void)
{
    //Set the time variable to whatever time is now.
    TimeLastChecked=SDL_GetTicks();
}
//Increment the fps number func.
void AC_C_FPS::IncrementFPS(void)
{
    //Increment the FPS counter.
    FpsNumber++;
}
//Change weather the FPS is shown or not.
void AC_C_FPS::ChangeShowState(void)
{
    //If the FPS is not being rendered right now...
    if(AC_RenderFPS==false)
    {
        //Then say that it should be.
        AC_RenderFPS=true;
    }
    //Otherwise, it must be rendering...
    else
    {
        //So tell the computer to stop.s
        AC_RenderFPS=false;
    }
}

////////////////EOF////////////////
