/*
    The digital clock class.

    Copyright 2010 James Russell
*/

//INCLUDES//
#include "digital_clock.h"

//External definitions.//
extern AC_C_SecondHand AC_SecondHand;
extern AC_C_Note AC_Note;
extern SDL_Surface *AC_DigiClock_Sec_Ones;
extern SDL_Surface *AC_DigiClock_Sec_Tens;
extern SDL_Surface *AC_DigiClock_Min_Ones;
extern SDL_Surface *AC_DigiClock_Min_Tens;
extern SDL_Surface *AC_DigiClock_Hrs_Ones;
extern SDL_Surface *AC_DigiClock_Hrs_Tens;
extern SDL_Surface *AC_DigiClock_Colon;
extern SDL_Surface *AC_DigiClock_Cover;
extern SDL_Surface *AC_UpOrDownSurf;
extern TTF_Font *AC_Font_Digital;
extern void AC_ShowSurface(SDL_Surface *AC_ShowSurfSrc, int x, int y);

////////////////CLASS////////////////
//Init values.
AC_C_DigiClock::AC_C_DigiClock(void)
{
    //Init all the times values.
    Seconds_Ones=Seconds_Tens=0;
    Minutes_Ones=Minutes_Tens=0;
    Hours_Ones=Hours_Tens=0;
    //Say that the timer hasn't started.
    Is_Paused=true;
    //Say that you are counting up, as default.
    UpOrDown=UP;
    //Convert all the int's that represent the time into str.
    //Seconds.
    sprintf(SecondsOnesChar,"%d",Seconds_Ones);
    sprintf(SecondsTensChar,"%d",Seconds_Tens);
    //Minutes.
    sprintf(MinutesOnesChar,"%d",Minutes_Ones);
    sprintf(MinutesTensChar,"%d",Minutes_Tens);
    //Hours.
    sprintf(HoursOnesChar,"%d",Hours_Ones);
    sprintf(HoursTensChar,"%d",Hours_Tens);
    //Set the default time that the counter will count own from.
    CountDown_SecondsOnes=CountDown_SecondsTens=0;
    CountDown_MinutesOnes=CountDown_MinutesTens=0;
    CountDown_HoursOnes=CountDown_HoursTens=0;
    //Make sure the "Set Time" graphics and functionality is not set.
    SetTimeBool=false;

    //Say you init the digital clock class.
    printf("DigiClock class constructed.\n");
}
//Reset the clock.
void AC_C_DigiClock::Inital_Setup(void)
{
    //Convert all the int's that represent the time into str.
    //Seconds.
    sprintf(SecondsOnesChar,"%d",Seconds_Ones);
    sprintf(SecondsTensChar,"%d",Seconds_Tens);
    //Minutes.
    sprintf(MinutesOnesChar,"%d",Minutes_Ones);
    sprintf(MinutesTensChar,"%d",Minutes_Tens);
    //Hours.
    sprintf(HoursOnesChar,"%d",Hours_Ones);
    sprintf(HoursTensChar,"%d",Hours_Tens);

    //Render the numbers.
    AC_DigiClock_Sec_Ones=TTF_RenderText_Solid(AC_Font_Digital,SecondsOnesChar,AC_Color_LEDRed);
    AC_DigiClock_Sec_Tens=TTF_RenderText_Solid(AC_Font_Digital,SecondsTensChar,AC_Color_LEDRed);
    AC_DigiClock_Min_Ones=TTF_RenderText_Solid(AC_Font_Digital,MinutesOnesChar,AC_Color_LEDRed);
    AC_DigiClock_Min_Tens=TTF_RenderText_Solid(AC_Font_Digital,MinutesTensChar,AC_Color_LEDRed);
    AC_DigiClock_Hrs_Ones=TTF_RenderText_Solid(AC_Font_Digital,HoursOnesChar,AC_Color_LEDRed);
    AC_DigiClock_Hrs_Tens=TTF_RenderText_Solid(AC_Font_Digital,HoursTensChar,AC_Color_LEDRed);
}
//Show the time.
void AC_C_DigiClock::Show_Time(void)
{
    //Show colons.
    AC_ShowSurface(AC_DigiClock_Colon,284,225);
    AC_ShowSurface(AC_DigiClock_Colon,351,225);
    //Show seconds.
    AC_ShowSurface(AC_DigiClock_Sec_Tens,387-AC_DigiClock_Sec_Tens->w,208);
    AC_ShowSurface(AC_DigiClock_Sec_Ones,418-AC_DigiClock_Sec_Ones->w,208);
    //Show mins.
    AC_ShowSurface(AC_DigiClock_Min_Tens,321-AC_DigiClock_Min_Tens->w,208);
    AC_ShowSurface(AC_DigiClock_Min_Ones,352-AC_DigiClock_Min_Ones->w,208);
    //Show hrs.
    AC_ShowSurface(AC_DigiClock_Hrs_Tens,255-AC_DigiClock_Hrs_Tens->w,208);
    AC_ShowSurface(AC_DigiClock_Hrs_Ones,286-AC_DigiClock_Hrs_Ones->w,208);
    //If the "Set Time" switch is on...
    if(SetTimeBool==true)
    {
        //Render the "Set Time" stuff.
        //Render the light that is on.
        AC_ShowSurface(AC_LightOn,446,138);
        //Render the button in the "on" position.
        AC_ShowSurface(AC_ButtonOn,463,227);
        //Render the arrows.
        //The up arrows.
        AC_ShowSurface(AC_ArrowUp,233,212);
        AC_ShowSurface(AC_ArrowUp,264,212);
        AC_ShowSurface(AC_ArrowUp,299,212);
        AC_ShowSurface(AC_ArrowUp,330,212);
        AC_ShowSurface(AC_ArrowUp,365,212);
        AC_ShowSurface(AC_ArrowUp,396,212);
        //The down arrows.
        AC_ShowSurface(AC_ArrowDown,234,263);
        AC_ShowSurface(AC_ArrowDown,265,263);
        AC_ShowSurface(AC_ArrowDown,299,263);
        AC_ShowSurface(AC_ArrowDown,330,263);
        AC_ShowSurface(AC_ArrowDown,365,263);
        AC_ShowSurface(AC_ArrowDown,396,263);
    }
    //Otherwise, the "Set Time" switch must be off.
    //So...
    else
    {
        //Render the button in the "off" position.
        AC_ShowSurface(AC_ButtonOff,463,227);
    }
    //Render the cover over all of this.
    AC_ShowSurface(AC_DigiClock_Cover,216,212);
}
//Pause/unpause the timer.
void AC_C_DigiClock::Pause(void)
{
    //If the program isn't in "Set Time" mode,
    //then you can pause or unpause the timer.
    if(SetTimeBool==false)
    {
        //If the timer is already paused...
        if(Is_Paused==true)
        {
            //Unpause the timer.
            Is_Paused=false;

            //Set the time.
            Set_Time();
        }
        //Otherwise, the timer must of been unpaused.
        else if(Is_Paused==false)
        {
            //So pause it.
            Is_Paused=true;
        }
    }
}
//Time checker and incrementor.
void AC_C_DigiClock::Count_Up(void)
{
    //Check if one second has passed.
    //If it has...
    if(SDL_GetTicks()>TimeLastChecked+1000)
    {
        //Increment the ones digit in the seconds.
        Seconds_Ones+=(SDL_GetTicks()-TimeLastChecked)/1000;
        //Then set the time.
        Set_Time();

        //If the ones digit in the seconds is 10...
        if(Seconds_Ones==10)
        {
            //Reset the ones position to 0.
            Seconds_Ones=0;
            //Then increment the tens position.
            Seconds_Tens++;

            //If the tens digit of the seconds is 6...
            if(Seconds_Tens==6)
            {
                //Reset the tens digit of the seconds.
                Seconds_Tens=0;
                //Add one to the minutes
                Minutes_Ones++;

                //If the minutes has been 10...
                if(Minutes_Ones==10)
                {
                    //Reset the ones digit of the minutes.
                    Minutes_Ones=0;
                    //Then increment the tens digit of the minutes.
                    Minutes_Tens++;

                    //If it's been 60 minutes...
                    if(Minutes_Tens==6)
                    {
                        //Reset the tens digit of the minutes.
                        Minutes_Tens=0;
                        //Then increment the ones digit of the hours.
                        Hours_Ones++;

                        //If it's been 10 hours...
                        if(Hours_Ones==10)
                        {
                            //Reset the ones position of the hours.
                            Hours_Ones=0;
                            //Then increment the tens digit of the hours.
                            Hours_Tens++;

                            //If it's been 100 hours...
                            if(Hours_Tens==10)
                            {
                                //Reset the whole time.
                                Seconds_Ones=Seconds_Tens=0;
                                Minutes_Ones=Minutes_Tens=0;
                                Hours_Ones=Hours_Tens=0;
                                //Then pause the clock and reset it.
                                Reset_Time();
                                Pause();
                                AC_SecondHand.Pause();
                                //Render the notice that you have stopped the clock.
                                AC_Note.RenderNotes("Counter has reached 100 hours.");
                                //Make a simple beep sound to tell the user that 100 hours has been reached.
                                Mix_PlayChannel(1,AC_S_Beep,0);
                            }
                        }
                    }
                }
            }
        }

        //Then render the new numbers.
        RenderTimeOnSurfs();
    }
}
//Set the current time.
void AC_C_DigiClock::Set_Time(void)
{
    //Set the current time.
    TimeLastChecked=SDL_GetTicks();
}
//Render the time to the surfs.
void AC_C_DigiClock::RenderTimeOnSurfs(void)
{
    //If the "Set Time" switch is off.
    if(SetTimeBool==false)
    {
        //Convert all the int's that represent the time into str.
        //Seconds.
        sprintf(SecondsOnesChar,"%d",Seconds_Ones);
        sprintf(SecondsTensChar,"%d",Seconds_Tens);
        //Minutes.
        sprintf(MinutesOnesChar,"%d",Minutes_Ones);
        sprintf(MinutesTensChar,"%d",Minutes_Tens);
        //Hours.
        sprintf(HoursOnesChar,"%d",Hours_Ones);
        sprintf(HoursTensChar,"%d",Hours_Tens);
    }
    //Otherwise, the "Set Time" switch must be on.
    //So...
    else
    {
        //Set the countdown numbers as the numbers to be rendered.
        sprintf(SecondsOnesChar,"%d",CountDown_SecondsOnes);
        sprintf(SecondsTensChar,"%d",CountDown_SecondsTens);
        sprintf(MinutesOnesChar,"%d",CountDown_MinutesOnes);
        sprintf(MinutesTensChar,"%d",CountDown_MinutesTens);
        sprintf(HoursOnesChar,"%d",CountDown_HoursOnes);
        sprintf(HoursTensChar,"%d",CountDown_HoursTens);
    }

    //Free the previous surfaces.
    SDL_FreeSurface(AC_DigiClock_Sec_Ones);
    SDL_FreeSurface(AC_DigiClock_Sec_Tens);
    SDL_FreeSurface(AC_DigiClock_Min_Ones);
    SDL_FreeSurface(AC_DigiClock_Min_Tens);
    SDL_FreeSurface(AC_DigiClock_Hrs_Ones);
    SDL_FreeSurface(AC_DigiClock_Hrs_Tens);

    //Render the numbers.
    AC_DigiClock_Sec_Ones=TTF_RenderText_Solid(AC_Font_Digital,SecondsOnesChar,AC_Color_LEDRed);
    AC_DigiClock_Sec_Tens=TTF_RenderText_Solid(AC_Font_Digital,SecondsTensChar,AC_Color_LEDRed);
    AC_DigiClock_Min_Ones=TTF_RenderText_Solid(AC_Font_Digital,MinutesOnesChar,AC_Color_LEDRed);
    AC_DigiClock_Min_Tens=TTF_RenderText_Solid(AC_Font_Digital,MinutesTensChar,AC_Color_LEDRed);
    AC_DigiClock_Hrs_Ones=TTF_RenderText_Solid(AC_Font_Digital,HoursOnesChar,AC_Color_LEDRed);
    AC_DigiClock_Hrs_Tens=TTF_RenderText_Solid(AC_Font_Digital,HoursTensChar,AC_Color_LEDRed);
}
//Reset the time to 0;
void AC_C_DigiClock::Reset_Time(void)
{
    //If the clock is set to the "count up" position...
    if(UpOrDown==UP)
    {
        //Just reset the time to 0.
        Seconds_Ones=Seconds_Tens=0;
        Minutes_Ones=Minutes_Tens=0;
        Hours_Ones=Hours_Tens=0;
    }
    //Otherwise, it must be set the the "count down" position.
    //So...
    else
    {
        //Reset the time to whatever was put in.
        Set_CountDown_Time();
    }

    //Render the text to the surfs.
    RenderTimeOnSurfs();
    //Then set the time.
    Set_Time();
}
//Temp test func for whatever needs testing.
void AC_C_DigiClock::Test_Func(void)
{
    //Set the time to whatever needs testing.
    Hours_Tens=9;   //99:59:55
    Hours_Ones=9;
    Minutes_Tens=5;
    Minutes_Ones=9;
    Seconds_Tens=5;
    Seconds_Ones=5;
    //Render the text to the surfs.
    RenderTimeOnSurfs();
}
//Return the seconds that have passed.
int AC_C_DigiClock::Return_Seconds(void)
{
    //Take the seconds parts and put them into the whole part.
    sprintf(SecondsWholeStr,"%s%s",SecondsTensChar,SecondsOnesChar);
    //Then put the whole seconds string into the integer.
    sscanf(SecondsWholeStr,"%d",&SecondsWholeInt);
    //Then return that integer, the seconds that the digiclock is on.
    return SecondsWholeInt;
}
//Time incrementing function.
void AC_C_DigiClock::RunClock(void)
{
    //If the timer was not paused.
    if(Is_Paused==false)
    {
        //If the clock is set in the "count up" position...
        if(UpOrDown==UP)
        {
            //Count up.
            Count_Up();
        }
        //Otherwise, it must be in the "count down" position.
        //So...
        else
        {
            //Count down.
            Count_Down();
        }

        //Rotate the second hand.
        AC_SecondHand.Rotate();
    }
}
//Time decrementing function.
void AC_C_DigiClock::Count_Down(void)
{
    //If 1 second has passed since the time that was last checked...
    if(SDL_GetTicks()>TimeLastChecked+1000)
    {
        //Decrement the ones digit in the seconds.
        Seconds_Ones-=(SDL_GetTicks()-TimeLastChecked)/1000;
        //Then set the time.
        Set_Time();

        //If the ones digit of the seconds has counted down past zero...
        if(Seconds_Ones<0)
        {
            //Reset the seconds ones position to 9.
            Seconds_Ones=9;
            //Then decrement the seconds tens position.
            Seconds_Tens--;

            //If the tens digit of the seconds has counted down past zero...
            if(Seconds_Tens<0)
            {
                //Reset the seconds tens back to 5.
                Seconds_Tens=5;
                //Then decrement the minutes ones position.
                Minutes_Ones--;

                //If the minutes ones position has counted past zero...
                if(Minutes_Ones<0)
                {
                    //Reset the minutes ones back to 9.
                    Minutes_Ones=9;
                    //Then decrement the minutes tens position.
                    Minutes_Tens--;

                    //If the minutes tens position has went past 0...
                    if(Minutes_Tens<0)
                    {
                        //Then reset the minutes tens position back to 5.
                        Minutes_Tens=5;
                        //Then decrement the hours one position.
                        Hours_Ones--;

                        //If the hours ones position has went past 0...
                        if(Hours_Ones<0)
                        {
                            //Reset the hours ones position back to 9.
                            Hours_Ones=9;
                            //Then decrement the hours tens position.
                            Hours_Tens--;

                            //If the hours tens position has went past 0...
                            if(Hours_Tens<0)
                            {
                                //Stop the clock and the second hand.
                                Pause();
                                AC_SecondHand.Pause();
                                //Then put all the numbers back to zero.
                                Seconds_Ones=Seconds_Tens=0;
                                Minutes_Ones=Minutes_Tens=0;
                                Hours_Ones=Hours_Tens=0;
                                //Say that the timer has reached the end.
                                AC_Note.RenderNotes("Timer has reached 0.");
                                //And make the ringing sound.
                                Mix_PlayChannel(0,AC_S_Ring,0);
                            }
                        }
                    }
                }
            }
        }

        //Then render the new numbers.
        RenderTimeOnSurfs();
    }
}
//Switch the counting state.
void AC_C_DigiClock::Switch_UpOrDown(void)
{
    //If the up or down position is set to up...
    if(UpOrDown==UP)
    {
        //Set it to down.
        UpOrDown=DOWN;
        //Render the text for the note.
        AC_Note.RenderUpOrDownText();
    }
    //Otherwise, it must be set to down.
    //So...
    else
    {
        //Set it to up.
        UpOrDown=UP;
        //Render the text for the note.
        AC_Note.RenderUpOrDownText();
    }

    //Render the text to the surfs.
    RenderTimeOnSurfs();
}
//Set the time that will be count down from.
void AC_C_DigiClock::Set_CountDown_Time(void)
{
    //Set the time to whatever needs to be count down from.
    Hours_Tens=CountDown_HoursTens;
    Hours_Ones=CountDown_HoursOnes;
    Minutes_Tens=CountDown_MinutesTens;
    Minutes_Ones=CountDown_MinutesOnes;
    Seconds_Tens=CountDown_SecondsTens;
    Seconds_Ones=CountDown_SecondsOnes;
    //Rotate the second hand.
    AC_SecondHand.Rotate();
}
//Switch the set time rendering and functionality.
void AC_C_DigiClock::Switch_SetTime(void)
{
    //If the "Set Time" rendering is off...
    if(SetTimeBool==false)
    {
        //If the counter is unpaused...
        if(Is_Paused==false)
        {
            //Pause the counter.
            Pause();
            AC_SecondHand.Pause();
        }
        //Turn it on.
        SetTimeBool=true;
        //Render the "Set Time" numbers.
        RenderTimeOnSurfs();
    }
    //Otherwise, it must be on.
    //So...
    else
    {
        //Set the countdown time.
        Set_CountDown_Time();
        //And turn it off.
        SetTimeBool=false;
    }
}
////////////////EOF////////////////
