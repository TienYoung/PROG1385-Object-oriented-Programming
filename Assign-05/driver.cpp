/*
* FILE : driver.cpp
* PROJECT : PROG1385 - Assignment #3
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-06-05
* DESCRIPTION :
* This file contains the main driver program for the AmFmRadio class. It implements
* a menu-driven interface that allows users to interact with an AmFmRadio object.
* The program provides options to toggle power, set volume, switch between AM and FM bands,
* set and select preset buttons, show current radio settings, scan frequencies up and down,
* and quit the program. It demonstrates the functionality of the AmFmRadio class
* in a user-friendly console application.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "PioneerCarRadio.h"

#include <iostream>
using namespace std;

/* ---------------------------------------------------------------------
 * In case you haven't seen an "enum" declaration before, here are a
 * couple of links to you to check out and read up about them ...
 * the concept of an "enum" is simple and is truly meant to clean up your
 * code and make it more readable ...
 *   1. https://www.codesdope.com/c-enum/
 *   2. https://en.cppreference.com/w/c/language/enum
 *   3. https://www.programiz.com/c-programming/c-enumeration
 * --------------------------------------------------------------------- */
enum menuItems
{
    kMenuNothing = 0,	// special constant for initialization only
    kMenuTogglePower = 1, kMenuSetVolume, kMenuToggleAMFM, kMenuSetButton, kMenuSelectButton,
    kMenuShowCurrentSettings, kMenuScanUp, kMenuScanDown, kMenuQuit
};


int main()
{
    int			volume_OK = 0;
    int			button_OK = 0;
    menuItems	choice = kMenuNothing;
    bool		on = true;
    PioneerCarRadio	jazzy;

    do
    {
        int key = _getch();

        switch (key)
        {
        case 'o':
            jazzy.PowerToggle();
            jazzy.ShowCurrentSettings();
            break;
        case '+':
            volume_OK = jazzy.SetVolume(jazzy.GetCurrentVolume() + 1);
            if (volume_OK == VolumeStatus::MUTE)
            {
                printf("\nVolume was set to 0.");
            }
            else if (volume_OK == VolumeStatus::FULL)
            {
                printf("\nVolume was set to 100.");
            }
            jazzy.ShowCurrentSettings();
            break;
        case '_':
            volume_OK = jazzy.SetVolume(jazzy.GetCurrentVolume() - 1);
            if (volume_OK == VolumeStatus::MUTE)
            {
                printf("\nVolume was set to 0.");
            }
            else if (volume_OK == VolumeStatus::FULL)
            {
                printf("\nVolume was set to 100.");
            }
            jazzy.ShowCurrentSettings();
            break;
        case '=':
            on = jazzy.IsRadioOn();
            if (on)
            {
                jazzy.ScanUp();
            }
            else
            {
                printf("\nYou must turn the radio on before you can use the scan button!\n");

            }
            jazzy.ShowCurrentSettings();
            break;
        case '-':
            on = jazzy.IsRadioOn();
            if (on)
            {
                jazzy.ScanDown();
            }
            else
            {
                printf("\nYou must turn the radio on before you can use the scan button!\n");

            }
            jazzy.ShowCurrentSettings();
            break;
        case 'b':
            on = jazzy.IsRadioOn();
            if (on)
            {
                jazzy.ToggleBand();

            }
            else
            {
                printf("\nThe radio must be turned on before the "
                    "band can be toggled!");
            }
            jazzy.ShowCurrentSettings();
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            on = jazzy.IsRadioOn();
            if (on)
            {
                button_OK = jazzy.SelectPresetButton(key - '0');
                if (button_OK == 0)
                {
                    printf("\nYou entered an invalid button number!");
                }
            }
            else
            {
                printf("\nYou must turn the radio on before you set the buttons!\n");
            }
            jazzy.ShowCurrentSettings();
            break;
        case '!':
            on = jazzy.IsRadioOn();
            if (on)
            {
                button_OK = jazzy.SetPresetButton(1);
                if (button_OK == 0)
                {
                    printf("\nYou entered an invalid button number!");
                }
            }
            else
            {
                printf("\nYou must turn the radio on before you set the buttons!\n");
            }
            jazzy.ShowCurrentSettings();
            break;
        case '@':
            on = jazzy.IsRadioOn();
            if (on)
            {
                button_OK = jazzy.SetPresetButton(2);
                if (button_OK == 0)
                {
                    printf("\nYou entered an invalid button number!");
                }
            }
            else
            {
                printf("\nYou must turn the radio on before you set the buttons!\n");
            }
            jazzy.ShowCurrentSettings();
            break;
        case '#':
            on = jazzy.IsRadioOn();
            if (on)
            {
                button_OK = jazzy.SetPresetButton(3);
                if (button_OK == 0)
                {
                    printf("\nYou entered an invalid button number!");
                }
            }
            else
            {
                printf("\nYou must turn the radio on before you set the buttons!\n");
            }
            jazzy.ShowCurrentSettings();
            break;
        case '$':
            on = jazzy.IsRadioOn();
            if (on)
            {
                button_OK = jazzy.SetPresetButton(4);
                if (button_OK == 0)
                {
                    printf("\nYou entered an invalid button number!");
                }
            }
            else
            {
                printf("\nYou must turn the radio on before you set the buttons!\n");
            }
            jazzy.ShowCurrentSettings();
            break;
        case '%':
            on = jazzy.IsRadioOn();
            if (on)
            {
                button_OK = jazzy.SetPresetButton(5);
                if (button_OK == 0)
                {
                    printf("\nYou entered an invalid button number!");
                }
            }
            else
            {
                printf("\nYou must turn the radio on before you set the buttons!\n");
            }
            jazzy.ShowCurrentSettings();
            break;
        case 'x':
            choice = kMenuQuit;
        default:
            break;

        } 

    } while (choice != kMenuQuit);

    printf("\nGoodbye!\n");
    return 0;


}