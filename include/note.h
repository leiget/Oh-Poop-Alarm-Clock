/*
    The include file that contains the note blitting class.

    Copyright 2010 James Russell
*/

//If note.h was not defined before,
//  define it now.
#ifndef NOTE_H
#define NOTE_H

//INCLUDES//
#include "main.h"

////////////////CLASS////////////////
class AC_C_Note
{
    private:
        //The string that will be rendered telling
        //  us if the counter is going up or down.
        char UpOrDown[15];
        //The char strings that will be the note lines.
        //The arrays will be a max of 36 chars, which include the null terminator.
        //So you can only have 34 chars to write the note.
        //There are 8 lines, which is what the first dimention of the array is.
        char NoteLines[8][35];
    public:
        //The constructor.
        AC_C_Note(void);
        //Function that initalizes everything that couldn't in the constructor.
        void Init(void);
        //The function that will render the up or down surface with text.
        void RenderUpOrDownText(void);
        //Render the text. This function automaticly sorts
        //the notes according to age.
        void RenderNotes(const char *NoteToBeRendered);
        //Render all the note surfaces with the appropriate text.
        void RenderTextToSurfs(void);
        //Show all the note surfaces.
        void ShowNoteSurfs(void);
};

//End the preprocessor if at top of file.
#endif

