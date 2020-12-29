/*
    The file that contains the note blitting class functions and such.

    Copyright 2010 James Russell
*/

//INCLUDES//
#include "note.h"

//External class definitions.//
extern AC_C_DigiClock AC_DigiClock;
extern SDL_Surface *AC_UpOrDownSurf;

////////////////CLASS////////////////
//The constructor.
AC_C_Note::AC_C_Note(void)
{
    //Render the text of the UpOrDown surface.
    RenderUpOrDownText();

    //Make all the note lines empty, with only null terminators.
    for(int count=0;count<=7;count++)
    {
        //Copy the null terminator into the line string.
        sprintf(NoteLines[count],"---");
    }

    //Say that the note class was constructed.
    printf("Note class constructed.\n");
}
//Function that initalizes everything that couldn't in the constructor.
void AC_C_Note::Init(void)
{
    //Render the "up or down" text to the surface.
    RenderUpOrDownText();
    //Render the surfaces. They will be empty, but hey will be there.
    RenderTextToSurfs();
}
//The function that will render the up or down surface with text.
void AC_C_Note::RenderUpOrDownText(void)
{
    //If the the timer is set to up...
    if(AC_DigiClock.UpOrDown==UP)
    {
        //Set the string to "up".
        sprintf(UpOrDown,"Counting: UP");
    }
    //Otherwise, the timer must be set to down.
    //So...
    else
    {
        //Set the string to "down".
        sprintf(UpOrDown,"Counting: DOWN");
    }

    //Free the surface.
    SDL_FreeSurface(AC_UpOrDownSurf);
    //Render the text to the surface.
    AC_UpOrDownSurf=TTF_RenderText_Blended(AC_Font_ArialBig,UpOrDown,AC_Color_Black);
}
//Render the text. This function automaticly sorts
//the notes according to age.
void AC_C_Note::RenderNotes(const char *NoteToBeRendered)
{
    //First off, check to see if the NoteToBeRendered is too long.
    //If it is...
    if(strlen(NoteToBeRendered)>=35)
    {
        //Say so.
        RenderNotes("String to be rendered is too long.");
        //Then return. This breaks out of this whole function.
        return;
    }

    //Check to see which note lines have already been rendered.
    //Depending on how many have been rendered, I will move
    //  all the preceding notes down one and fill in the first note.
    for(int count=0;count<=7;count++)
    {
        //If the string is empty...
        if(!strcmp(NoteLines[count],"---"))
        {
            //Move all the other strings down to the next line.
            for(int line=count;line>=1;line--)
            {
                //Copy the last line into the current line.
                sprintf(NoteLines[line],"%s",NoteLines[line-1]);
            }

            //Write in the string into the first note line.
            sprintf(NoteLines[0],"%s",NoteToBeRendered);

            //Break out of this whole for loop.
            //There is no need to check the remaining lines.
            break;
        }
        //Otherwise, if the count went all the way up to 7,
        //  that means that none of the lines were empty.
        //  Because, if they were, this loop would've been
        //  broken, as you can see in the if statement above.
        //So...
        else if(count==7)
        {
            //Move all but the last string line into the next.
            for(int line=count-1;line>=0;line--)
            {
                //Copy the current line into the next line.
                sprintf(NoteLines[line+1],"%s",NoteLines[line]);
            }

            //Then insert the note that is to be rendered
            //  in the newest note slot.
            sprintf(NoteLines[0],"%s",NoteToBeRendered);
        }
    }

    //Then render all the text to surfs.
    RenderTextToSurfs();
}
//Render all the note surfaces with the appropriate text.
void AC_C_Note::RenderTextToSurfs(void)
{
    //Go through all the surfaces, rendering each one.
    for(int count=0;count<=7;count++)
    {
        //Free the surface before writing text to it.
        SDL_FreeSurface(AC_NoteLinesSurfs[count]);
        //Then render the text to the surface.
        AC_NoteLinesSurfs[count]=TTF_RenderText_Blended(AC_Font_ArialSmall,NoteLines[count],AC_Color_Black);
    }
}
//Show all the note surfaces.
void AC_C_Note::ShowNoteSurfs(void)
{
    //Simply show all the surfaces for the note class.
    //Show the UpOrDown surface.
    AC_ShowSurface(AC_UpOrDownSurf,67,315);
    //Show the note surfaces.
    AC_ShowSurface(AC_NoteLinesSurfs[0],68,346-10);
    AC_ShowSurface(AC_NoteLinesSurfs[1],68,358-10);
    AC_ShowSurface(AC_NoteLinesSurfs[2],68,371-10);
    AC_ShowSurface(AC_NoteLinesSurfs[3],68,383-10);
    AC_ShowSurface(AC_NoteLinesSurfs[4],68,396-10);
    AC_ShowSurface(AC_NoteLinesSurfs[5],68,408-10);
    AC_ShowSurface(AC_NoteLinesSurfs[6],68,421-10);
    AC_ShowSurface(AC_NoteLinesSurfs[7],68,433-10);
}

////////////////EOF////////////////
