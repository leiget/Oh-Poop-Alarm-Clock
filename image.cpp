/*
    Contains functions for loading images andything else to do with images/textures.

    Copyright James Russell 2010

    AC_LoadTex() function based off of LazyFoo image loading function.
        Design used with permission.
*/

//INCLUDES//
#include "image.h"

////////////////FUNCTIONS////////////////
//Load image unto SDL_Surface.//
//TexFilename is the filename. Type flag is the transparency type, like CC or Alpha.
//CC_R, CC_G, and CC_B is the color that is going to be transparent in colorkeyed textures.
//If you set the Alpha to 128, that's a special case for alpha and it will be faster blitting.
SDL_Surface *AC_LoadTex(const char *AC_TexFilename,Uint8 AC_TypeFlag,Uint8 CK_R,Uint8 CK_G,Uint8 CK_B,bool AC_RLE)
{
    //Temp surfaces.
    SDL_Surface *AC_TempSurface=NULL;
    SDL_Surface *AC_FinalSurface=NULL;

    //Load the image into the temp surface.
    AC_TempSurface=IMG_Load(AC_TexFilename);

    //If the image didn't load...
    if(!AC_TempSurface)
    {
        //Say so and why.
        printf("***Image not loaded: %s***\n",IMG_GetError());
        //Return NULL
        return NULL;
    }

    //Optimize the surface according to
    //  whatever the output is to be.
    //If no trans was set...
    if(AC_TypeFlag==AC_NONE)
    {
        //Convert the temp surface to the screen format. And that's it.
        AC_FinalSurface=SDL_DisplayFormat(AC_TempSurface);
    }
    //Otherwise, if colorkey trans was set...
    else if(AC_TypeFlag==AC_CK)
    {
        //Get the color key that was input at function call.
        Uint32 AC_CKey=SDL_MapRGB(AC_TempSurface->format,CK_R,CK_G,CK_B);
        //Then set the color key onto the temp surface.
        //If RLEAccel is set...
        if(AC_RLE==true)
        {
            //Then set the colorkey with RLE accelleration.
            SDL_SetColorKey(AC_TempSurface,SDL_SRCCOLORKEY|SDL_RLEACCEL,AC_CKey);
        }
        //Otherwise, if RLEAccel was not set...
        else
        {
            //Then set the colorkey without RLEAccel.
            SDL_SetColorKey(AC_TempSurface,SDL_SRCCOLORKEY,AC_CKey);
        }
        //Then convert the temp surface into the final surface with format change.
        AC_FinalSurface=SDL_DisplayFormat(AC_TempSurface);
    }
    //Otherwise, if alpha trans was set...
    else if(AC_TypeFlag==AC_A)
    {
        //Convert the surface to the screen format with alpha functionality.
        AC_FinalSurface=SDL_DisplayFormatAlpha(AC_TempSurface);
    }

    //Say you loaded the file.
    printf("Loaded %s.\n",AC_TexFilename);

    //Return the final optimized surface.
    return AC_FinalSurface;
}

////////////////EOF////////////////////
