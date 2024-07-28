/*
* FILE : PioneerAM.h
* PROJECT : PROG1385 - Assignment #6
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-07-26
* DESCRIPTION :
* This is a header file for the PioneerAM class. It defines the structure and
* interface for a simulated Pioneer AM radio, including functionality for power
* control, frequency tuning, preset management, volume control, and display
* settings. The class provides methods to interact with the radio, change
* stations, set presets, adjust volume, and view current settings. This class
* extends the functionality of the PioneerCarRadio base class.
*/

#pragma once

#include "PioneerCarRadio.h"

#include <cstdio>
#include <cstring>

/*
* NAME : PioneerAM
* PURPOSE : The PioneerAM class models the behavior of a Pioneer AM radio.
*           It extends the PioneerCarRadio class to provide specific functionality
*           for AM band selection and management. The class allows users to interact
*           with the radio, change stations, set presets, adjust volume, and view
*           current settings specific to AM band.
*/
class PioneerAM : public PioneerCarRadio
{
public:
    /*
    * FUNCTION : PioneerAM (constructor)
    * DESCRIPTION :
    *   Initializes a new PioneerAM object. Sets the radio name to "Pioneer XS440-AM"
    *   and the band to AM.
    * PARAMETERS :
    *   None
    * RETURNS :
    *   None (constructor)
    */
	PioneerAM(void) : PioneerCarRadio()
	{
		m_name = "Pioneer XS440-AM";
		strcpy_s(band, sizeof(band), "AM");
	}

    /*
    * FUNCTION : ~PioneerAM (destructor)
    * DESCRIPTION :
    *   Cleans up any resources used by the PioneerAM object and outputs a message
    *   indicating the destruction of the radio object.
    * PARAMETERS :
    *   None
    * RETURNS :
    *   None (destructor)
    */
	virtual ~PioneerAM(void)
	{
		printf("Destroying %s Radio\n", GetName());
	}

    /*
    * FUNCTION : ToggleFrequency
    * DESCRIPTION :
    *   Ensures the radio band remains set to AM.
    * PARAMETERS :
    *   None
    * RETURNS :
    *   void
    */
	virtual void ToggleFrequency(void) override
	{
		strcpy_s(band, sizeof(band), "AM");
	}
};