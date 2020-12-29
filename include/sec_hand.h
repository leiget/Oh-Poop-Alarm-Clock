/*
    The header file that contains all the functions/classes/whatever it takes to make the second hand move.

    Copyright 2010 James Russell
*/

//If this file was not defined already,
//  then define it now.
#ifndef SEC_HAND_H
#define SEC_HAND_H

//INCLUDES//
#include "main.h"

////////////////CLASS////////////////
//The class that moves the second hand.
//That's all it does.
class AC_C_SecondHand
{
    private:
        //The second hand base position.
        int x, y;
        //The degrees to rotate the hand.
        double Degrees;
        //Bool that says weather the second hand is paused or not.
        bool Is_Paused;
    public:
        AC_C_SecondHand(void);
        void Init(void);
        void Pause(void);
        void Rotate(void);
        void ShowSecondHand(void);
        void Reset(void);
};

//End the preproccessor if at top of file.
#endif
