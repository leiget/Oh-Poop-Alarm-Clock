/*
    Contains global variables and functions for audio functioality.

    Copyright James Russell 2010.
*/

//If audio.h was not included before,
//  include it now.
#ifndef AUDIO_H
#define AUDIO_H

//INCLUDES//
//Local//
#include "main.h"

//Global variables.//
extern int AC_WorkingAudioFreq;
extern Uint16 AC_WorkingAudioFrmt;
extern int AC_WorkingAudioChan;

//External definitions//
extern int AC_AudioFreq;
extern Uint16 AC_AudioFrmt;
extern int AC_AudioChan;
extern int AC_AudioChunkSize;

////////////////FUNCTIONS////////////////
//Start SDL_mixer.//
bool AC_StartMixer(void);
//Quit SDL_mixer.//
void AC_QuitMixer(void);
//Allocate the number of channels needed.//
bool AC_AllocateChannels(void);

//End preproccessor if at top of file.
#endif
