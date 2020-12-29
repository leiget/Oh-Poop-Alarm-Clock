/*
    Contains all the things needed to use events in SDL.

    Copyright James Russell 2010
*/

//INCLUDES//
#include "event.h"

//CLASS_DECLARES//
//Main event. Don't know if I need more than one.
SDL_Event AC_MainEvent;

//External func/classes.//
extern AC_C_FPS AC_FPS;
extern AC_C_DigiClock AC_DigiClock;
extern AC_C_SecondHand AC_SecondHand;

////////////////FUNCTIONS////////////////
//Check input function.//
void AC_CheckInput(void)
{
    //If an event has happened...
    if(SDL_PollEvent(&AC_MainEvent))
    {
        //Check to see if the user has pressed the "X" button,
        //  in the top-right corner of window. Yes, that "X".
        //If it was...
        if(AC_MainEvent.type==SDL_QUIT)
        {
            //Set the quit switch to true.
            AC_Quit=true;
        }

        //Check if it was a key press.
        //If it was...
        if(AC_MainEvent.type==SDL_KEYDOWN)
        {
            //See what one it was.
            switch(AC_MainEvent.key.keysym.sym)
            {
                //If it was esc, quit the program.
                case SDLK_ESCAPE: AC_Quit=true; break;
                case SDLK_f: AC_FPS.ChangeShowState(); break;
                case SDLK_SPACE: AC_DigiClock.Pause(); AC_SecondHand.Pause(); break;
                case SDLK_r: AC_DigiClock.Reset_Time(); AC_SecondHand.Reset(); break;
                case SDLK_RETURN: AC_DigiClock.Switch_UpOrDown(); break;
                //case SDLK_RIGHT: AC_DigiClock.Test_Func(); break;
                case SDLK_F12: SDL_SaveBMP(AC_Screen,"screenshot.bmp"); break;
                default: break;
            }
        }

        //Check the mouse input.
        AC_CheckMouseInput();
    }
}
//Check mouse input.//
void AC_CheckMouseInput(void)
{
    //If a mouse button was pressed...
    if(AC_MainEvent.type==SDL_MOUSEBUTTONDOWN)
    {
        //And if it was the left button...
        if(AC_MainEvent.button.button==SDL_BUTTON_LEFT)
        {
            //If it was in the area of the "Set Time" button...
            if(AC_MainEvent.button.x>463 && AC_MainEvent.button.y>227
                && AC_MainEvent.button.x<(463+AC_ButtonOff->w) && AC_MainEvent.button.y<(227+AC_ButtonOff->h))
            {
                //Switch the "Set Time" switch.
                AC_DigiClock.Switch_SetTime();
            }

            //Check the "Set Time" arrow input.
            AC_CheckSetTimeArrowInput();
        }
    }
}
//Check the input for the "Set Time" arrows.//
void AC_CheckSetTimeArrowInput(void)
{
    //Check the up arrows first.
    //Hours tens.
    if(AC_MainEvent.button.x>233 && AC_MainEvent.button.y>212
        && AC_MainEvent.button.x<(233+AC_ArrowUp->w) && AC_MainEvent.button.y<(212+AC_ArrowUp->h))
    {
        //If the hours tens digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_HoursTens<9)
        {
            //Add one to the hours tens digit.
            AC_DigiClock.CountDown_HoursTens++;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }
    //Hours ones.
    if(AC_MainEvent.button.x>264 && AC_MainEvent.button.y>212
        && AC_MainEvent.button.x<(264+AC_ArrowUp->w) && AC_MainEvent.button.y<(212+AC_ArrowUp->h))
    {
        //If the hours tens digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_HoursOnes<9)
        {
            //Add one to the hours tens digit.
            AC_DigiClock.CountDown_HoursOnes++;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }
    //Minutes tens.
    if(AC_MainEvent.button.x>299 && AC_MainEvent.button.y>212
        && AC_MainEvent.button.x<(299+AC_ArrowUp->w) && AC_MainEvent.button.y<(212+AC_ArrowUp->h))
    {
        //If the hours tens digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_MinutesTens<5)
        {
            //Add one to the hours tens digit.
            AC_DigiClock.CountDown_MinutesTens++;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }
    //Minutes ones.
    if(AC_MainEvent.button.x>330 && AC_MainEvent.button.y>212
        && AC_MainEvent.button.x<(330+AC_ArrowUp->w) && AC_MainEvent.button.y<(212+AC_ArrowUp->h))
    {
        //If the hours tens digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_MinutesOnes<9)
        {
            //Add one to the hours tens digit.
            AC_DigiClock.CountDown_MinutesOnes++;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }
    //Seconds tens.
    if(AC_MainEvent.button.x>365 && AC_MainEvent.button.y>212
        && AC_MainEvent.button.x<(365+AC_ArrowUp->w) && AC_MainEvent.button.y<(212+AC_ArrowUp->h))
    {
        //If the hours tens digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_SecondsTens<5)
        {
            //Add one to the hours tens digit.
            AC_DigiClock.CountDown_SecondsTens++;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }
    AC_ShowSurface(AC_ArrowUp,365,212);
    //Seconds ones.
    if(AC_MainEvent.button.x>396 && AC_MainEvent.button.y>212
        && AC_MainEvent.button.x<(396+AC_ArrowUp->w) && AC_MainEvent.button.y<(212+AC_ArrowUp->h))
    {
        //If the seconds one digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_SecondsOnes<9)
        {
            //Add one to the seconds ones digit.
            AC_DigiClock.CountDown_SecondsOnes++;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }

    //Now check the down arrows.
    //Hours tens.
    if(AC_MainEvent.button.x>234 && AC_MainEvent.button.y>263
        && AC_MainEvent.button.x<(234+AC_ArrowUp->w) && AC_MainEvent.button.y<(263+AC_ArrowUp->h))
    {
        //If the seconds one digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_HoursTens>0)
        {
            //Subtract one to the seconds ones digit.
            AC_DigiClock.CountDown_HoursTens--;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }
    //Hours ones.
    if(AC_MainEvent.button.x>265 && AC_MainEvent.button.y>263
        && AC_MainEvent.button.x<(265+AC_ArrowUp->w) && AC_MainEvent.button.y<(263+AC_ArrowUp->h))
    {
        //If the seconds one digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_HoursOnes>0)
        {
            //Subtract one to the seconds ones digit.
            AC_DigiClock.CountDown_HoursOnes--;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }
    //Minutes tens.
    if(AC_MainEvent.button.x>299 && AC_MainEvent.button.y>263
        && AC_MainEvent.button.x<(299+AC_ArrowUp->w) && AC_MainEvent.button.y<(263+AC_ArrowUp->h))
    {
        //If the seconds one digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_MinutesTens>0)
        {
            //Subtract one to the seconds ones digit.
            AC_DigiClock.CountDown_MinutesTens--;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }
    //Minutes ones.
    if(AC_MainEvent.button.x>330 && AC_MainEvent.button.y>263
        && AC_MainEvent.button.x<(330+AC_ArrowUp->w) && AC_MainEvent.button.y<(263+AC_ArrowUp->h))
    {
        //If the seconds one digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_MinutesOnes>0)
        {
            //Subtract one to the seconds ones digit.
            AC_DigiClock.CountDown_MinutesOnes--;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }
    //Seconds tens.
    if(AC_MainEvent.button.x>365 && AC_MainEvent.button.y>263
        && AC_MainEvent.button.x<(365+AC_ArrowUp->w) && AC_MainEvent.button.y<(263+AC_ArrowUp->h))
    {
        //If the seconds one digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_SecondsTens>0)
        {
            //Subtract one to the seconds ones digit.
            AC_DigiClock.CountDown_SecondsTens--;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }
    //Seconds ones.
    if(AC_MainEvent.button.x>396 && AC_MainEvent.button.y>263
        && AC_MainEvent.button.x<(396+AC_ArrowUp->w) && AC_MainEvent.button.y<(263+AC_ArrowUp->h))
    {
        //If the seconds one digit is within the 0-9 range...
        if(AC_DigiClock.CountDown_SecondsOnes>0)
        {
            //Subtract one to the seconds ones digit.
            AC_DigiClock.CountDown_SecondsOnes--;
            //Then render the numbers.
            AC_DigiClock.RenderTimeOnSurfs();
        }
    }
}
////////////////EOF////////////////
