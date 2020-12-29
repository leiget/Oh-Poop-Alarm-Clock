/*
    Contains functions for setting up and shutting down the alarm clock program.
    Generaly, anything to do with the init.

    Copyright James Russell 2010.
*/

//If this header wasn't included before,
//  include it now.
#ifndef SETUP_H
#define SETUP_H

//INCLUDES//
//Local//
#include "main.h"

////////////////FUNCTIONS////////////////
//Setup SDL and all other libs.//
int AC_StartEngine(void);
//Quit SDL and all other systems.//
void AC_QuitEngine(void);
//Check which error happened when you started the engine.
void AC_CheckEngineError(void);

//End the define at the top of this file.
#endif
