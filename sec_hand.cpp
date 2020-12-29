/*
    Contains all the functions/classes/whatever it takes to make the second hand move.

    Copyright 2010 James Russell
*/

//INCLUDES//
#include "sec_hand.h"

//External functions and classes.//
extern AC_C_DigiClock AC_DigiClock;
extern SDL_Surface *AC_SecondHandSurfRotate;
extern SDL_Surface *AC_SecondHandSurf;
extern SDL_Surface *AC_SecondHandCover;

////////////////CLASS////////////////
//Class constructor.
AC_C_SecondHand::AC_C_SecondHand(void)
{
    //Set the base positions.
    x=95;
    y=125;
    //Set the degrees to 0.
    Degrees=360;
    //Say that the second hand is paused.
    Is_Paused=true;
}
//This initalizes anything that couldn't before.
void AC_C_SecondHand::Init(void)
{
    //Rotate the surf so that the show func has something to show.
    AC_SecondHandSurfRotate=rotozoomSurface(AC_SecondHandSurf,Degrees,1,0);
}
//Pause or unpause function.
void AC_C_SecondHand::Pause(void)
{
    //If the timer is already paused...
    if(Is_Paused==true)
    {
        //Unpause the timer.
        Is_Paused=false;

        //Set the degrees to the current second.
        Degrees=-(AC_DigiClock.Return_Seconds()*6);
    }
    //Otherwise, the timer must of been unpaused.
    else if(Is_Paused==false)
    {
        //So pause it.
        Is_Paused=true;
    }
}
//Rotate the surface function.
void AC_C_SecondHand::Rotate(void)
{
    //If the second hand is not paused...
    if(Is_Paused==false)
    {
        //Calculate the degrees that it should be pointing at.
        Degrees=-(AC_DigiClock.Return_Seconds()*6);
        //Free the surface before rotating it again.
        SDL_FreeSurface(AC_SecondHandSurfRotate);
        //Then rotate the surface.
        AC_SecondHandSurfRotate=rotozoomSurface(AC_SecondHandSurf,Degrees,1,0);
    }
}
//Show the second hand function.
void AC_C_SecondHand::ShowSecondHand(void)
{
    //Just show the surf.
    AC_ShowSurface(AC_SecondHandSurfRotate,x-AC_SecondHandSurfRotate->w/2,y-AC_SecondHandSurfRotate->h/2);
    //Then show the cover over that.
    AC_ShowSurface(AC_SecondHandCover,53,78);
}
//Reset the second hand position to 0.
void AC_C_SecondHand::Reset(void)
{
    //Just reset the degrees to 0.
    Degrees=0;
}

////////////////EOF////////////////////
