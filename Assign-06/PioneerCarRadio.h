/*
* FILE : PioneerCarRadio.h
* PROJECT : PROG1385 - Assignment #5
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-07-20
* DESCRIPTION :
*   This header file declares the PioneerCarRadio class, which inherits from
*   the AmFmRadio class. It defines the additional functionality for handling
*   user keystrokes specific to a car radio.
*/

#pragma once

#include "AmFmRadio.h"

/*
* NAME : PioneerCarRadio
* PURPOSE : The PioneerCarRadio class models the behavior of a car AM/FM radio.
*           It extends the functionality of the AmFmRadio class with additional
*           features specific to a car radio, including handling user input
*           through keystrokes.
*/
class PioneerCarRadio : public AmFmRadio
{
public:
	//constructors
	PioneerCarRadio(void);
	//destruction
	virtual ~PioneerCarRadio(void);

	virtual const char* GetName(void);

    //processes user keystrokes to interact with the radio, handling input 
    //to control the radio functions such as changing stations, adjusting volume, 
    //and toggling power
	virtual void ProcessUserKeyStroke(void);
};

