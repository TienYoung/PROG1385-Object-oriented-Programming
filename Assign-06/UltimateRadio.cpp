/*
* FILE : carDriver.cpp
* PROJECT : PROG1385 - Assignment #5
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-07-20
* DESCRIPTION :
*   This file contains the main function to drive the PioneerCarRadio class.
*   It creates an instance of the PioneerCarRadio and processes user keystrokes
*   to interact with the radio functionalities.
*/

#include "PioneerCarRadio.h"

int main(void)
{
    PioneerCarRadio	pioneer_XS440;

    pioneer_XS440.HandleKeystroke();

    return 0;
}