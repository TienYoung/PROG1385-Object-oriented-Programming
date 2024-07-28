/*
* FILE : carDriver.cpp
* PROJECT : PROG1385 - Assignment #6
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-07-26
* DESCRIPTION :
*   This file contains the main function to drive the PioneerCarRadio class.
*   It creates an instance of the PioneerCarRadio and processes user keystrokes
*   to interact with the radio functionalities.
*/

#include "PioneerWorld.h"

#include <stdexcept>
#include <iostream>
#include <conio.h>

#define HANDLE_EXCEPTION(expression)                                \
do{                                                                 \
    try                                                             \
    {                                                               \
        expression;                                                 \
    }                                                               \
    catch (const std::invalid_argument& e)                          \
    {                                                               \
        std::cerr << "INVALID_ARUGMENT: " << e.what() << std::endl; \
        return 0;                                                   \
    }                                                               \
    catch (const std::bad_alloc& e)                                 \
    {                                                               \
        std::cerr << "BAD_ALLOC: " << e.what() << std::endl;        \
        return 0;                                                   \
    }                                                               \
} while(false)                                                     

PioneerCarRadio* createRadio(const char* type);

enum Arguments { PROGRAM_NAME, FIRST_ARGUMENT, ARGUMENTS_NUM };

int main(int argc, char* argv[])
{
    if (argc < ARGUMENTS_NUM)
    {
        return 0;
    }

    PioneerCarRadio* pRadio = nullptr;

    HANDLE_EXCEPTION(pRadio = createRadio(argv[FIRST_ARGUMENT]));
    do
    {
        pRadio->ProcessUserKeyStroke();
        delete pRadio;
        pRadio = nullptr;

        int keystroke = _getch();
        switch (keystroke)
        {
        case 'c':
            HANDLE_EXCEPTION(pRadio = createRadio("-car"));
            break;
        case 'a':
            HANDLE_EXCEPTION(pRadio = createRadio("-am"));
            break;
        case 'w':
            HANDLE_EXCEPTION(pRadio = createRadio("-world"));
            break;
        case 'x':
            delete pRadio;
            pRadio = nullptr;
            break;
        }
    } while (pRadio);

    return 0;
}

/*
* FUNCTION : createRadio
* DESCRIPTION :
*   Creates and returns a pointer to a new radio object based on the specified type.
*   The function supports creating PioneerCarRadio, PioneerAM, and PioneerWorld objects.
*   If an unsupported type is specified, an exception is thrown.
* PARAMETERS :
*   const char* type : A string specifying the type of radio to create. Supported types are:
*                      - "-car"   : Creates a PioneerCarRadio object.
*                      - "-am"    : Creates a PioneerAM object.
*                      - "-world" : Creates a PioneerWorld object.
* RETURNS :
*   PioneerCarRadio* : A pointer to the newly created radio object.
* THROWS :
*   std::invalid_argument : If the specified type is not supported.
*/
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
    else
    {
        throw std::invalid_argument("This program only supports -car, -am and -world.\n");
    }
}