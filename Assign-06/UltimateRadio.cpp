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

#include "PioneerWorld.h"

PioneerCarRadio* createRadio(const char* type);

enum Arguments { PROGRAM_NAME, FIRST_ARGUMENT, ARGUMENTS_NUM };

int main(int argc, char* argv[])
{
    if (argc < ARGUMENTS_NUM)
    {
        return 0;
    }

    PioneerCarRadio* radio = nullptr;

    radio = createRadio(argv[FIRST_ARGUMENT]);

    if (radio)
    {
        radio->ProcessUserKeyStroke();
    }

    return 0;
}

PioneerCarRadio* createRadio(const char* type)
{
	if (strcmp(type, "-car") == 0)
	{
		return new PioneerCarRadio();
	}
	else if (strcmp(type, "-am") == 0)
	{
		return new PioneerAM();
	}
	else if (strcmp(type, "-world") == 0)
	{
		return new PioneerWorld();
	}

	return nullptr;
}