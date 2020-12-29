/*
    Frames per second counting class.

    FPS class based off what I was taught by LazyFoo's tutorials on lazyfoo.net.
    It isn't nessesarally the same. I didn't copy it, because I don't remember it all
        exactly.

    Class initialization at end of file.

    Copyright 2010 James Russell
*/

//If fps.h wasn't defined already,
//  define it now.
#ifndef FPS_H
#define FPS_H

//INCLUDES//
#include "main.h"

////////////////CLASS////////////////
//FPS class for keeping track of and showing the FPS.
class AC_C_FPS
{
    private:
        //This is the time that is compared to the current time.
        //It's set when the program starts and when the FPS is
        //  shown.
        Uint32 TimeLastChecked;
        //This is the actual FPS number, telling us the FPS.
        Uint32 FpsNumber;
        //This is the FPS as a string.
        char FpsAsString[16];
    public:
        //Initalizes variables.
        AC_C_FPS(void);
        //Init what couldn't when the class was contructed.
        void InitFPS(void);
        //Show the FPS.
        void ShowFPS(void);
        //Check to see if a certain amount of time has passed
        //  in milliseconds.
        void CheckTime(Uint32 Milliseconds);
        //Set the current time to compare to.
        void SetTime(void);
        //Increment the FPS number.
        void IncrementFPS(void);
        //Change weather the FPS is rendered or not.
        void ChangeShowState(void);
};

//End preproccessor if at top of this file.
#endif
