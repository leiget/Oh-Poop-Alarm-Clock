/*
    The digital clock class.

    Copyright 2010 James Russell
*/

//If digital_clock.h was not defined before,
//  define it now.
#ifndef DIGITAL_CLOCK_H
#define DIGITAL_CLOCK_H

//INCLUDES//
#include "main.h"

////////////////CLASS////////////////
//The digital clock class.//
class AC_C_DigiClock
{
    private:
        //The time for checking if 1 seconds passed.
        Uint32 TimeLastChecked;
        //The unsigned int's for the times on the clock.
        //Each digit has a number.
        int8_t Seconds_Ones, Seconds_Tens;
        int8_t Minutes_Ones, Minutes_Tens;
        int8_t Hours_Ones, Hours_Tens;
        //The whole seconds string as an integer.
        int SecondsWholeInt;
        //Converted char str from int's for use as text.
        char SecondsOnesChar[2];
        char SecondsTensChar[2];
        char MinutesOnesChar[2];
        char MinutesTensChar[2];
        char HoursOnesChar[2];
        char HoursTensChar[2];
        //The whole seconds string.
        char SecondsWholeStr[3];
        //Time incrementing function.
        void Count_Up(void);
        //Time decrementing function.
        void Count_Down(void);
    public:
        //Paused switch.
        bool Is_Paused;
        //State to tell us wheater the clock is going up or down.
        bool UpOrDown;
        //Switch for telling the computer to render the "Set Time" graphics.
        bool SetTimeBool;
        //The integers that hold the time to be count down from.
        int8_t CountDown_SecondsOnes, CountDown_SecondsTens;
        int8_t CountDown_MinutesOnes, CountDown_MinutesTens;
        int8_t CountDown_HoursOnes, CountDown_HoursTens;
        //Init values.
        AC_C_DigiClock(void);
        //Reset time.
        void Inital_Setup(void);
        //Blit the time.
        void Show_Time(void);
        //Pause/unpause the timer.
        void Pause(void);
        //Set the current time.
        void Set_Time(void);
        //Render the time to the surfs.
        void RenderTimeOnSurfs(void);
        //Reset the time to 0;
        void Reset_Time(void);
        //Temp test function, for whatever needs testing in this class.
        void Test_Func(void);
        //Return the time that has passed.
        int Return_Seconds(void);
        //Run the clock.
        void RunClock(void);
        //Switch the counting state.
        void Switch_UpOrDown(void);
        //Set the time that will be count down from.
        void Set_CountDown_Time(void);
        //Switch the set time rendering and functionality.
        void Switch_SetTime(void);
};

//End preprocessor if at top of file.
#endif
