/*
    Contains global variables and functions for audio functioality.

    Copyright James Russell 2010.
*/

//INCLUDES//
#include "audio.h"

//Global variables.//
int AC_WorkingAudioFreq;
Uint16 AC_WorkingAudioFrmt;
int AC_WorkingAudioChan;

////////////////FUNCTIONS////////////////
//Start SDL_mixer.//
bool AC_StartMixer(void)
{
    //Say you're going to open the mixer.
    printf("\nStarting the audio system.\n");

    //Try to open SDL_mixer
    //If it fails...
    if(Mix_OpenAudio(AC_AudioFreq,AC_AudioFrmt,AC_AudioChan,AC_AudioChunkSize)==-1)
    {
        //Say so and why.
        printf("***SDL_mixer failed to init: %s***\n",Mix_GetError());
        //Return false for fail.
        return false;
    }

    //Otherwise, it must of succeded.
    //Say that SDL_mixer was initalized.
    printf("SDL_mixer initalized.\n");

    ////Printing the specs.////
    //Set what the specs actually are into the appropriate variables.
    //If it fails...
    if(Mix_QuerySpec(&AC_WorkingAudioFreq,&AC_WorkingAudioFrmt,&AC_WorkingAudioChan)==0)
    {
        //Just say so.
        printf("***Error querying audio specs: %s***\n",Mix_GetError());
    }
    //Otherwise, it must of succeded.
    //So...
    else
    {
        //Say the actual specs of the audio.
        //First, the working audio freqincy.
        printf("Freq=%d\n",AC_WorkingAudioFreq);
        //Next, the working audio format.
        //Print the format identifier...
        printf("Frmt=");
        //Then print the actual format name.
        switch((int)AC_WorkingAudioFrmt)
        {
            case AUDIO_U8: printf("AUDIO_U8\n"); break;
            case AUDIO_S8: printf("AUDIO_S8\n"); break;
            case AUDIO_U16LSB: printf("AUDIO_U16LSB\n"); break;
            case AUDIO_S16LSB: printf("AUDIO_S16LSB\n"); break;
            case AUDIO_U16MSB: printf("AUDIO_U16MSB\n"); break;
            default: printf("***Problem getting audio format info.***\n");
        }
        //Last, print the working audio channels.
        printf("Channels=%d\n",AC_WorkingAudioChan);
    }

    //Now allocate the channels.
    //If it failed...
    if(AC_AllocateChannels()==false)
    {
        //Return false.
        return false;
    }

    //Return true for success.
    return true;
}
//Quit SDL_mixer.//
void AC_QuitMixer(void)
{
    //Set the audio spec variables back to 0;
    AC_WorkingAudioFreq=0;
    AC_WorkingAudioFrmt=0;
    AC_WorkingAudioChan=0;

    //Check to see if SDL_mixer was intialized.
    int AC_TimesMixInit=Mix_QuerySpec(&AC_WorkingAudioFreq,&AC_WorkingAudioFrmt,&AC_WorkingAudioChan);

    //If Mix_QuerySpec didn't work...
    if(!AC_TimesMixInit && !AC_WorkingAudioFreq && !AC_WorkingAudioFrmt && !AC_WorkingAudioChan)
    {
        //Say so.
        printf("***Error getting number of times audio opened.***\n");
    }

    //If SDL_mixer wasn't even opened...
    if(!AC_TimesMixInit)
    {
        //Just say so.
        printf("***SDL_mix not even open.***\n");
    }

    //If it did work and the audio was actually opened...
    if(AC_TimesMixInit)
    {
        //Shutdown SDL_mixer according to how many times it was opened.
        for(int TempForInt=0;TempForInt<AC_TimesMixInit;TempForInt++)
        {
            //Shutdown SDL_mixer.
            Mix_CloseAudio();
        }
    }

    //See if SDL_mix was closed.
    AC_TimesMixInit=Mix_QuerySpec(&AC_WorkingAudioFreq,&AC_WorkingAudioFrmt,&AC_WorkingAudioChan);
    //If it was...
    if(!AC_TimesMixInit)
    {
        //Say so.
        printf("SDL_mix closed.\n");
    }
    //Otherwise, it must still be opened.
    else
    {
        //Say so and how many times it is still opened.
        printf("***SDL_mix still open %d times.***\n",AC_TimesMixInit);
    }
}
//Allocate the number of channels needed.//
bool AC_AllocateChannels(void)
{
    //Temp integer for storing how many channels were allocated.
    int AC_Temp_AllocatedChannels=0;

    //Allocate the channels needed.
    AC_Temp_AllocatedChannels=Mix_AllocateChannels(AC_SoundChannels);
    //If it failed to load as many channels as specified...
    if(AC_Temp_AllocatedChannels!=AC_SoundChannels)
    {
        //Check to see if any channels were allocated.
        //If none were allocated...
        if(AC_Temp_AllocatedChannels==0)
        {
            //Say so and why.
            printf("***No audio channels allocated: %s***\n",Mix_GetError());
            //Return false.
            return false;
        }
        //Otherwise, at least one channel must of been allocated.
        //So...
        else
        {
            //Say so and how many channels were allocated.
            printf("***Specified number of channels not allocated.***\n");
            printf("***Number of allocated channels: %d***\n",AC_Temp_AllocatedChannels);
        }
    }

    //Otherwise, everything must of been allocated correctly.
    //Say so.
    printf("All channels allocated successfully.\n");
    //Return true for success.
    return true;
}

////////////////EOF////////////////
