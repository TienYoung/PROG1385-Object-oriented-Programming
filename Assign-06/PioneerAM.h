#pragma once

#include "PioneerCarRadio.h"

#include <cstdio>
#include <cstring>

class PioneerAM : public PioneerCarRadio
{
public:
	PioneerAM(void) : PioneerCarRadio()
	{
		m_name = "Pioneer XS440-AM";
		strcpy_s(band, sizeof(band), "AM");
	}

	virtual ~PioneerAM(void)
	{
		printf("Destroying %s Radio\n", GetName());
	}

	virtual void ToggleFrequency(void) override
	{
		strcpy_s(band, sizeof(band), "AM");
	}
};