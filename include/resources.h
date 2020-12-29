/*
    Contains the resources and functions for using this program. Mostly SDL_Surfaces and such.

    Copyright James Russell 2010
*/

//If resources.h was not declared before,
//  declare it now.
#ifndef RESOURCES_H
#define RESOURCES_H

//INCLUDES//
//Local//
#include "main.h"

////////////////RESOURCES////////////////
//SDL_Surfaces.//
extern SDL_Surface *AC_Screen;
extern SDL_Surface *AC_BG;
extern SDL_Surface *AC_FPSSurf;
extern SDL_Surface *AC_DigiClock_Sec_Ones;
extern SDL_Surface *AC_DigiClock_Sec_Tens;
extern SDL_Surface *AC_DigiClock_Min_Ones;
extern SDL_Surface *AC_DigiClock_Min_Tens;
extern SDL_Surface *AC_DigiClock_Hrs_Ones;
extern SDL_Surface *AC_DigiClock_Hrs_Tens;
extern SDL_Surface *AC_DigiClock_Colon;
extern SDL_Surface *AC_DigiClock_Cover;
extern SDL_Surface *AC_SecondHandSurfRotate;
extern SDL_Surface *AC_SecondHandSurf;
extern SDL_Surface *AC_SecondHandCover;
extern SDL_Surface *AC_UpOrDownSurf;
extern SDL_Surface *AC_NoteLinesSurfs[8];
extern SDL_Surface *AC_ArrowUp;
extern SDL_Surface *AC_ArrowDown;
extern SDL_Surface *AC_LightOn;
extern SDL_Surface *AC_ButtonOn;
extern SDL_Surface *AC_ButtonOff;
extern SDL_Surface *AC_CreditSurf;
extern SDL_Surface *AC_Logo;
//SDL_ttf font.//
extern TTF_Font *AC_Font_Digital;
extern TTF_Font *AC_Font_ArialBig;
extern TTF_Font *AC_Font_ArialSmall;
//SDL_mixer sound chunks.
extern Mix_Chunk *AC_S_Ring;
extern Mix_Chunk *AC_S_Beep;

////////////////FUNCTIONS////////////////
//Load all surfaces.//
bool AC_LoadAllSurfs(void);
//Free surfaces.//
void AC_FreeAllSurfs(void);
//Open fonts.//
bool AC_OpenFonts(void);
//Close fonts.//
void AC_CloseFonts(void);
//Free resources.//
void AC_FreeResources(void);
//Open all resources.//
bool AC_OpenAllResources(void);
//Load the sound chunks.//
bool AC_LoadSoundChunks(void);
//Free the sound chunks.//
void AC_FreeSoundChunks(void);

//End preprocessor if at top of file.
#endif
