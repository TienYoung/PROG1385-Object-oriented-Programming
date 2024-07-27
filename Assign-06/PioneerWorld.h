#pragma once

#include "PioneerAM.h"

#define AM_MIN   531
#define AM_MAX  1602
#define AM_STEP    9

class PioneerWorld : public PioneerAM
{
public:
	PioneerWorld(void) : PioneerAM()
	{
		m_name = "Pioneer XS440-WRLD";
		for (int i = 0; i < 5; ++i)
		{
			button[i].AMFreq = AM_MIN;
		}
		current_station.AMFreq = AM_MIN;
	}

	virtual ~PioneerWorld()
	{
		printf("Destroying %s Radio\n", GetName());
	}

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