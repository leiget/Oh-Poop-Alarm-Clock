/*
    Contains the resources and functions for using this program. Mostly SDL_Surfaces and such.

    Copyright James Russell 2010
*/

//INCLUDES//
#include "resources.h"

//External function definitions.//
extern const int AC_NONE;
extern const int AC_CK;
extern const int AC_A;
extern void AC_QuitEngine(void);
extern SDL_Surface *AC_LoadTex(const char *AC_TexFilename,Uint8 AC_TypeFlag=AC_NONE,Uint8 CK_R=0,Uint8 CK_G=0,Uint8 CK_B=0,bool AC_RLE=true);

////////////////RESOURCES////////////////
//SDL_Surfaces.//
SDL_Surface *AC_Screen;
SDL_Surface *AC_BG;
SDL_Surface *AC_FPSSurf;
SDL_Surface *AC_DigiClock_Sec_Ones;
SDL_Surface *AC_DigiClock_Sec_Tens;
SDL_Surface *AC_DigiClock_Min_Ones;
SDL_Surface *AC_DigiClock_Min_Tens;
SDL_Surface *AC_DigiClock_Hrs_Ones;
SDL_Surface *AC_DigiClock_Hrs_Tens;
SDL_Surface *AC_DigiClock_Colon;
SDL_Surface *AC_DigiClock_Cover;
SDL_Surface *AC_SecondHandSurfRotate;
SDL_Surface *AC_SecondHandSurf;
SDL_Surface *AC_SecondHandCover;
SDL_Surface *AC_UpOrDownSurf;
SDL_Surface *AC_NoteLinesSurfs[8];
SDL_Surface *AC_ArrowUp;
SDL_Surface *AC_ArrowDown;
SDL_Surface *AC_LightOn;
SDL_Surface *AC_ButtonOn;
SDL_Surface *AC_ButtonOff;
SDL_Surface *AC_CreditSurf;
SDL_Surface *AC_Logo;
//SDL_ttf font.
TTF_Font *AC_Font_Digital;
TTF_Font *AC_Font_ArialBig;
TTF_Font *AC_Font_ArialSmall;
//SDL_mixer sound chunks.
Mix_Chunk *AC_S_Ring;
Mix_Chunk *AC_S_Beep;

////////////////FUNCTIONS////////////////
//Load all surfaces.//
bool AC_LoadAllSurfs(void)
{
    //Load the background image.
    AC_BG=AC_LoadTex("media/BG.png");
    //If it failed...
    if(AC_BG==NULL)
    {
        //Return false.
        return false;
    }

    //Load the colon texture.
    AC_DigiClock_Colon=AC_LoadTex("media/colon.png",AC_CK,255,255,255);
    //If it didn't load...
    if(AC_DigiClock_Colon==NULL)
    {
        //Return false.
        return false;
    }

    //Load the cover texture.
    AC_DigiClock_Cover=AC_LoadTex("media/cover.png",AC_A);
    //If it didn't load...
    if(AC_DigiClock_Cover==NULL)
    {
        //Return false.
        return false;
    }

    //Load the second hand texture.
    AC_SecondHandSurf=AC_LoadTex("media/second.png",AC_A);
    //If it failed...
    if(AC_SecondHandSurf==NULL)
    {
        //Return false.
        return false;
    }

    //Load the second hand cover.
    AC_SecondHandCover=AC_LoadTex("media/secondhand_cover.png",AC_A);
    //If it failed...
    if(AC_SecondHandCover==NULL)
    {
        //Return false.
        return false;
    }

    //Load the arrow up and down texture.
    AC_ArrowUp=AC_LoadTex("media/arrow_up.png",AC_A);
    AC_ArrowDown=AC_LoadTex("media/arrow_down.png",AC_A);
    //If they both didn't load...
    if(AC_ArrowUp==NULL || AC_ArrowDown==NULL)
    {
        //Return false.
        return false;
    }

    //Load the light on texture.
    AC_LightOn=AC_LoadTex("media/light_on.png",AC_A);
    //If it failed...
    if(!AC_LightOn)
    {
        //Return false.
        return false;
    }

    //Load the "Button On" texture.
    AC_ButtonOn=AC_LoadTex("media/button_on.png",AC_NONE);
    //If it failed...
    if(!AC_ButtonOn)
    {
        //Return false.
        return false;
    }

    //Load the "Button Off" texture.
    AC_ButtonOff=AC_LoadTex("media/button_off.png",AC_NONE);
    //If it failed...
    if(!AC_ButtonOff)
    {
        //Return false.
        return false;
    }

    //Load the logo.
    AC_Logo=AC_LoadTex("media/logo.png",AC_A);
    //If it didn't load...
    if(!AC_Logo)
    {
        //Return false.
        return false;
    }

    //Say they all loaded.
    printf("All textures loaded.\n");
    //Then return true for success.
    return true;
}
//Free surfaces.//
void AC_FreeAllSurfs(void)
{
    //Free them surfaces, man.
    //AND DON'T HOLD BACK!
    SDL_FreeSurface(AC_BG);
    SDL_FreeSurface(AC_FPSSurf);
    SDL_FreeSurface(AC_DigiClock_Sec_Ones);
    SDL_FreeSurface(AC_DigiClock_Sec_Tens);
    SDL_FreeSurface(AC_DigiClock_Min_Ones);
    SDL_FreeSurface(AC_DigiClock_Min_Tens);
    SDL_FreeSurface(AC_DigiClock_Hrs_Ones);
    SDL_FreeSurface(AC_DigiClock_Hrs_Tens);
    SDL_FreeSurface(AC_DigiClock_Colon);
    SDL_FreeSurface(AC_DigiClock_Cover);
    SDL_FreeSurface(AC_SecondHandSurfRotate);
    SDL_FreeSurface(AC_SecondHandSurf);
    SDL_FreeSurface(AC_SecondHandCover);
    SDL_FreeSurface(AC_UpOrDownSurf);
    for(int count=0;count<8;count++)
    {
        SDL_FreeSurface(AC_NoteLinesSurfs[count]);
    }
    SDL_FreeSurface(AC_ArrowUp);
    SDL_FreeSurface(AC_ArrowDown);
    SDL_FreeSurface(AC_LightOn);
    SDL_FreeSurface(AC_ButtonOff);
    SDL_FreeSurface(AC_ButtonOn);
    SDL_FreeSurface(AC_CreditSurf);
    SDL_FreeSurface(AC_Logo);
}
//Open fonts.//
bool AC_OpenFonts(void)
{
    //Open the font.
    AC_Font_Digital=TTF_OpenFont("media/DS_DIGI.TTF",65);
    //If it failed to open...
    if(AC_Font_Digital==NULL)
    {
        //Say so and why.
        printf("***Error opening font: %s***\n",TTF_GetError());
        //Then return false.
        return false;
    }

    //Then open the arial font with a big setting.
    AC_Font_ArialBig=TTF_OpenFont("media/LiberationSans-Bold.ttf",20);
    //If it failed...
    if(AC_Font_ArialBig==NULL)
    {
        //Say so and why.
        printf("***Error opening font: %s***\n",TTF_GetError());
        //Then return false.
        return false;
    }

    //Open the small font, for note writing.
    AC_Font_ArialSmall=TTF_OpenFont("media/LiberationSans-Regular.ttf",12);
    //If it failed...
    if(AC_Font_ArialSmall==NULL)
    {
        //Say so and why.
        printf("***Error opening font: %s***\n",TTF_GetError());
        //Then return false.
        return false;
    }

    //Otherwise, it must of worked.
    //Say so.
    printf("Loaded fonts.\n");
    //Then return true.
    return true;
}
//Close fonts.//
void AC_CloseFonts(void)
{
    //If the digital font was loaded...
    if(!AC_Font_Digital)
    {
        //Just close the font.
        TTF_CloseFont(AC_Font_Digital);
        //Just to be sure.
        AC_Font_Digital=NULL;
    }

    //If the big arial font was loaded...
    if(!AC_Font_ArialBig)
    {
        //Then close the big font.
        TTF_CloseFont(AC_Font_ArialBig);
        //Just to be sure.
        AC_Font_ArialBig=NULL;
    }

    //If the small arial font was loaded...
    if(!AC_Font_ArialSmall)
    {
        //Then close the small arial font.
        TTF_CloseFont(AC_Font_ArialSmall);
        //Just to be sure.
        AC_Font_ArialSmall=NULL;
    }
}
//Free resources.//
void AC_FreeResources(void)
{
    //Free the fonts.
    AC_CloseFonts();
    //Free the sound chunks.
    AC_FreeSoundChunks();
    //Free the surfs.
    AC_FreeAllSurfs();
}
//Open all resources.//
bool AC_OpenAllResources(void)
{
    //Load the textures.
    //If it failed...
    if(AC_LoadAllSurfs()==false)
    {
        //Say so.
        printf("***Error loading textures.***\n");
        //Return false for fail.
        return false;
    }

    //Load all the fonts used.
    //If that failed...
    if(AC_OpenFonts()==false)
    {
        //Say so.
        printf("***Error loading fonts.***\n");
        //Return false for fail.
        return false;
    }

    //Load the sounds.
    //If that failed...
    if(AC_LoadSoundChunks()==false)
    {
        //Say so.
        printf("***Error loading sounds.***\n");
        //Return false for fail.
        return false;
    }

    //Otherwise, all the resources must of been loaded.
    //Say so.
    printf("All resources loaded.\n");
    //Return true for success.
    return true;
}
//Load sound chunks.//
bool AC_LoadSoundChunks(void)
{
    //Load the beep sound effect.
    AC_S_Beep=Mix_LoadWAV("media/beep.wav");
    //If it failed...
    if(!AC_S_Beep)
    {
        //Say so and why.
        printf("***Failed to load sound: %s***\n",Mix_GetError());
        //Return false.
        return false;
    }

    //Load the ring sound effect.
    AC_S_Ring=Mix_LoadWAV("media/ring.wav");
    //If it failed...
    if(!AC_S_Ring)
    {
        //Say so and why.
        printf("***Failed to load sound: %s***\n",Mix_GetError());
        //Return false.
        return false;
    }

    //Return true for success.
    return true;
}
//Free the sound chunks.//
void AC_FreeSoundChunks(void)
{
    //Free the chunks.
    Mix_FreeChunk(AC_S_Beep);
    Mix_FreeChunk(AC_S_Ring);
}

////////////////EOF////////////////
