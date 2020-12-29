/*
    Contains functions for setting up and shutting down the alarm clock program.
    Generaly, anything to do with the init.

    Copyright James Russell 2010.
*/

//INCLUDES//
#include "setup.h"

//External definitions//
extern void AC_FreeResources(void);
extern bool AC_InitTTF(void);
extern bool AC_SetupVideo(void);
extern void AC_QuitTTF(void);
extern bool AC_StartMixer(void);
extern void AC_QuitMixer(void);

////////////////FUNCTIONS////////////////
//Setup SDL and all other libs.//
int AC_StartEngine(void)
{
    //Make a space to seperate the start engine messages from everything else.
    printf("\n");

    //Say that you are starting the engine.
    printf("Starting the engine. Vroom, vroom.\n");

    //Start SDL.
    //If it failed...
    if(!AC_StartSDL())
    {
        //Return cariable for SDL_Init_Fail.
        //  The error was already printed in the AC_StartSDL() function.
        return SDL_Init_Fail;
    }

    //Setup audio/SDL_mixer.
    //If it failed...
    if(!AC_StartMixer())
    {
        //Say you are going to quit because of the error.
        //The error was already told in the AC_StartMixer() function.
        printf("***Quitting because of failed SDL_mix init.***\n");
        //Return the int for failed mixer init.
        return Mix_Init_Fail;
    }

    //Init SDL_ttf.
    //If it fails...
    if(!AC_InitTTF())
    {
        //Return the int for TTF_Init_Fail.
        //The error was already told in the AC_InitTTF() func.
        return TTF_Init_Fail;
    }

    //Say the engine was started.
    printf("\nEngine started.\n");

    //Setup video.
    //If it failed...
    if(AC_SetupVideo()==false)
    {
        //Return false.
        //The error was already reported in the AC_SetupVideo() func.
        return VideoSetup_Fail;
    }

    //Newline to seperate engine start messages from everythign else.
    printf("\n");

    //Return 0 for success.
    return 0;
}
//Quit SDL and all other systems.//
void AC_QuitEngine(void)
{
    //Newline to seperate quit from every other message.
    printf("\n");

    ////RESOURCES////
    AC_FreeResources();

    ////TTF////
    AC_QuitTTF();

    ////MIXER////
    AC_QuitMixer();

    ////SDL////
    AC_QuitSDL();
}
//Check which error happened when you started the engine.
void AC_CheckEngineError(void)
{
        if(AC_EngineError==SDL_Init_Fail)
        {
            printf("***SDL_Init_Fail***\n");
        }
        if(AC_EngineError==Mix_Init_Fail)
        {
            printf("***Mix_Init_Fail***\n");
        }
        if(AC_EngineError==TTF_Init_Fail)
        {
            printf("***TTF_Init_Fail***\n");
        }
        if(AC_EngineError==VideoSetup_Fail)
        {
            printf("***VideoSetup_Fail***\n");
        }
}

////////////////EOF////////////////
