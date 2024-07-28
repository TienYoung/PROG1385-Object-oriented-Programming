/*
* FILE : PioneerWorld.h
* PROJECT : PROG1385 - Assignment #6
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-07-26
* DESCRIPTION :
* This file contains the implementation of the PioneerWorld class. It extends
* the functionality of the PioneerAM class to provide specific functionality
* for a simulated AM radio with world frequencies. The class allows users to
* interact with the radio, change stations, set presets, adjust volume, and
* view current settings specific to the world AM band.
*/

#pragma once

#include "PioneerAM.h"

#define AM_MIN   531
#define AM_MAX  1602
#define AM_STEP    9

/*
* NAME : PioneerWorld
* PURPOSE : The PioneerWorld class models the behavior of a Pioneer AM radio
*           with world frequencies. It extends the PioneerAM class to provide
*           specific functionality for AM band selection and management.
*           The class allows users to interact with the radio, change stations,
*           set presets, adjust volume, and view current settings specific to
*           the world AM band.
*/
class PioneerWorld : public PioneerAM
{
public:
	/*
    * FUNCTION : PioneerWorld (constructor)
    * DESCRIPTION :
    *   Initializes a new PioneerWorld object. Sets the radio name to "Pioneer XS440-WRLD"
    *   and initializes preset buttons and the current station to the minimum AM frequency.
    * PARAMETERS :
    *   None
    * RETURNS :
    *   None (constructor)
    */
	PioneerWorld(void) : PioneerAM()
	{
		m_name = "Pioneer XS440-WRLD";
		for (int i = 0; i < 5; ++i)
		{
			button[i].AMFreq = AM_MIN;
		}
		current_station.AMFreq = AM_MIN;
	}

	/*
    * FUNCTION : ~PioneerWorld (destructor)
    * DESCRIPTION :
    *   Cleans up any resources used by the PioneerWorld object and outputs a message
    *   indicating the destruction of the radio object.
    * PARAMETERS :
    *   None
    * RETURNS :
    *   None (destructor)
    */
	virtual ~PioneerWorld()
	{
		printf("Destroying %s Radio\n", GetName());
	}

	/*
    * FUNCTION : ScanUp
    * DESCRIPTION :
    *   Increases the current station frequency by 9 kHz. If the current station is at
    *   the maximum frequency (1602 kHz), it wraps around to the minimum frequency (531 kHz).
    * PARAMETERS :
    *   None
    * RETURNS :
    *   void
    */
	virtual void ScanUp(void) override
	{
		//if current_station is 1602, the current_station becomes 531
		if (current_station.AMFreq == AM_MAX)
		{
			current_station.AMFreq = AM_MIN;
		}
		else
		{
			current_station.AMFreq = current_station.AMFreq + AM_STEP;
		}
	}


	/*
	* FUNCTION : ScanDown
	* DESCRIPTION :
	*   Decreases the current station frequency by 9 kHz. If the current station is at
	*   the minimum frequency (531 kHz), it wraps around to the maximum frequency (1602 kHz).
	* PARAMETERS :
	*   None
	* RETURNS :
	*   void
	*/
	virtual void ScanDown(void) override
	{
		//if current_station is 531, the current_station becomes 1602
		if (current_station.AMFreq == AM_MIN)
		{
			current_station.AMFreq = AM_MAX;
		}
		else
		{
			current_station.AMFreq = current_station.AMFreq - AM_STEP;
		}
	}
};