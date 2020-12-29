/*
    Contains functions for loading images andything else to do with images/textures.

    Copyright James Russell 2010

    AC_LoadTex() function based off of LazyFoo image loading function.
        Design used with permission.
*/

//If image.h was not defined already,
//  define it now.
#ifndef IMAGE_H
#define IMAGE_H

//INCLUDES//
//Local//
#include "main.h"

////////////////FUNCTIONS////////////////
//Load image unto SDL_Surface.//
//TexFilename is the filename. Type flag is the transparency type, like CC or Alpha.
//CC_R, CC_G, and CC_B is the color that is going to be transparent in colorkeyed textures.
//If you set the Alpha to 128, that's a special case for alpha and it will be faster blitting.
SDL_Surface *AC_LoadTex(const char *AC_TexFilename,Uint8 AC_TypeFlag,Uint8 CK_R,Uint8 CK_G,Uint8 CK_B,bool AC_RLE);

//End preprocessor if at top of of file.
#endif
