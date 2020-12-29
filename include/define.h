/*
    Includes all the major, system wide definitions for use in all the program.

    Copyright James Russell 2010
*/

//If define.h wasn't included before,
//  include it now.
#ifndef DEFINE_H
#define DEFINE_H

//INCLUDES//
//Local//
#include "main.h"

////////////////DEFINES////////////////
//Audio definitions.//
extern int AC_AudioFreq;
extern Uint16 AC_AudioFrmt;
extern int AC_AudioChan;
extern int AC_AudioChunkSize;
extern int AC_SoundChannels;
//Digital clock definitions.
#define UP  1
#define DOWN 0
//Image definitions.//
extern const int AC_NONE;
extern const int AC_CK;
extern const int AC_A;
//Engine error return variable.
extern int AC_EngineError;
//FPS varables.//
extern bool AC_RenderFPS;
//Loop variable.//
extern bool AC_Quit;
//SDL_Init flags.
extern Uint32 AC_SDL_InitFlags;
//Setup fail codes.//
extern const int SDL_Init_Fail;
extern const int Mix_Init_Fail;
extern const int TTF_Init_Fail;
extern const int VideoSetup_Fail;
//TTF variables and definitions.//
extern SDL_Color AC_Color_LightGrey;
extern SDL_Color AC_Color_LEDRed;
extern SDL_Color AC_Color_Black;
//Video definitions.//
extern const int AC_Screen_Width;
extern const int AC_Screen_Height;
extern const int AC_Screen_BPP;
extern const Uint32 AC_Screen_Flags;
//Window manager info.//
extern const char *AC_WindowCaption;
extern const char *AC_WindowIconName;

//End preproccessor if at top of file.
#endif
