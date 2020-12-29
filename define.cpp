/*
    Includes all the major, system wide definitions for use in all the program.

    Copyright James Russell 2010
*/

//INCLUDES//
#include "define.h"

////////////////DEFINES////////////////
//Audio definitions.//
int AC_AudioFreq=44100;
Uint16 AC_AudioFrmt=MIX_DEFAULT_FORMAT;
int AC_AudioChan=2;
int AC_AudioChunkSize=4096;
int AC_SoundChannels=2;
//Image definitions.//
const int AC_NONE=0;
const int AC_CK=1;
const int AC_A=2;
//Engine error return variable.
int AC_EngineError=0;
//FPS varables.//
bool AC_RenderFPS=false;
//Loop variable.//
bool AC_Quit=false;
//SDL_Init flags.
Uint32 AC_SDL_InitFlags=SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER;
//Setup fail codes.//
const int SDL_Init_Fail=1;
const int Mix_Init_Fail=2;
const int TTF_Init_Fail=3;
const int VideoSetup_Fail=4;
//TTF variables and definitions.//
SDL_Color AC_Color_LightGrey={220,220,230};
SDL_Color AC_Color_LEDRed={255,0,0};
SDL_Color AC_Color_Black={0,0,0};
//Video definitions.//
const int AC_Screen_Width=640;
const int AC_Screen_Height=480;
const int AC_Screen_BPP=0;
const Uint32 AC_Screen_Flags=SDL_ANYFORMAT;
//Window manager info.//
const char *AC_WindowCaption="Oh! Poop! Alarm Clock";
const char *AC_WindowIconName="Oh! Poop! Alarm Clock";

////////////////EOF////////////////
