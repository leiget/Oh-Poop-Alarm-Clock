/*
    An alarm clock program for keeping track of my exercise routine.
    Uses SDL, SDL_ttf, SDL_image, and SDL_mixer. Phew!

    Copyright James Russell 2010.
*/

//INCDLUES//
//Local.
#include "main.h"

////////////////CLASS_INIT////////////////
//Fps class.
AC_C_FPS AC_FPS;
//The digital clock class init.
AC_C_DigiClock AC_DigiClock;
//The second hand class.
AC_C_SecondHand AC_SecondHand;
//The note class.
AC_C_Note AC_Note;

////////////////MAIN////////////////
int main(int argc, char *atdv[])
{
    //Start the engine.
    AC_EngineError=AC_StartEngine();
    //If it fails...
    if(AC_EngineError!=0)
    {
        //Find out which error it was and print it.
        AC_CheckEngineError();
        //Stop the engine.
        AC_QuitEngine();
        //Return code 1.
        return 1;
    }

    //Try to load all the resources.
    //If it failed...
    if(AC_OpenAllResources()==false)
    {
        //Say so.
        printf("***Resources failed to open.***\n");
        //Stop the engine.
        AC_QuitEngine();
        //Return code 2.
        return 2;
    }

    ////////CLASS_INIT////////
    //Start FPS timer.
    AC_FPS.SetTime();
    //And init what couldn't when the class was contructed.
    AC_FPS.InitFPS();
    //Do the inital setup that you couldn't in the class constructor.
    AC_DigiClock.Inital_Setup();
    //Init the second hand class.
    AC_SecondHand.Init();
    //Init the note class.
    AC_Note.Init();
    //////////////////////////

    ////////MAIN_LOOP////////
    while(AC_Quit==false)
    {
        //Run the clock.
        AC_DigiClock.RunClock();

        ////////GRAPHICS////////
        //Show the background.
        AC_ShowSurface(AC_BG,0,0);
        //Show the digital clock.
        AC_DigiClock.Show_Time();
        //Show the second hand.
        AC_SecondHand.ShowSecondHand();
        //Show the note surfaces.
        AC_Note.ShowNoteSurfs();
        //Show the FPS.
        AC_FPS.ShowFPS();

        //Update screen.
        SDL_UpdateRect(AC_Screen,0,0,640,480);
        ////////////////////////

        ////////FPS////////
        //Increment the FPS number.
        AC_FPS.IncrementFPS();
        //FPS timer.
        AC_FPS.CheckTime(1000);
        ///////////////////

        ////////INPUT////////
        //Check the input from the user.
        AC_CheckInput();
        /////////////////////
    }

    ////QUIT////
    //Quit the engine.
    AC_QuitEngine();
    ////////////

    //Return 0 for successful program quit.
    return 0;
}

////////////////EOF////////////////////
