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
#include "AmFmRadio.h"

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
    int			button_num = 0;
    menuItems	choice = kMenuNothing;
    char		buf[20] = { 0 };
    bool		on = true;
    AmFmRadio	jazzy(on);

    cout << "a";
    do
    {
        printf("\n\nMAIN MENU\n");
        printf("=========\n\n");
        printf("1.  Toggle Power\n");
        printf("2.  Set Volume\n");
        printf("3.  Toggle AM / FM Band\n");
        printf("4.  Set a Preset Button \n");
        printf("5.  Select a Preset Button \n");
        printf("6.  Show Current Settings\n");
        printf("7.  Scan Up \n");
        printf("8.  Scan Down \n");
        printf("9.  Quit the Program\n");
        printf("\nMake a selection from the menu\n");
        fgets(buf, sizeof buf, stdin);
        choice = (menuItems)atoi(buf);

        switch (choice)
        {
        case kMenuTogglePower:
            jazzy.PowerToggle();
            break;
        case kMenuSetVolume:
            volume_OK = jazzy.SetVolume();
            if (volume_OK == 0)
            {
                printf("\nVolume was set to 0.");
            }
            else if (volume_OK == 2)
            {
                printf("\nVolume was set to 100.");
            }
            break;

        case kMenuToggleAMFM:
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
            break;
        case kMenuSetButton:
            on = jazzy.IsRadioOn();
            if (on)
            {
                printf("\nWhich button do you want to set?");
                fgets(buf, sizeof buf, stdin);
                button_num = atoi(buf) - 1;
                button_OK = jazzy.SetPresetButton(button_num);
                if (button_OK == 0)
                {
                    printf("\nYou entered an invalid button number!");
                }
            }
            else
            {
                printf("\nYou must turn the radio on before you set the buttons!\n");
            }
            break;
        case kMenuSelectButton:
            on = jazzy.IsRadioOn();
            if (on)
            {
                printf("\nEnter the number of the preset button: ");
                fgets(buf, 20, stdin);
                button_num = atoi(buf) - 1;
                button_OK = jazzy.SelectPresetButton(button_num);
                if (button_OK == 0)
                {
                    printf("\nYou entered an invalid button number!");
                }
            }
            else
            {
                printf("\nYou must turn the radio on before you set the buttons!\n");
            }
            break;
        case kMenuShowCurrentSettings:
            jazzy.ShowCurrentSettings();
            break;
        case kMenuScanUp:
            on = jazzy.IsRadioOn();
            if (on)
            {
                jazzy.ScanUp();
            }
            else
            {
                printf("\nYou must turn the radio on before you can use the scan button!\n");

            }
            break;
        case kMenuScanDown:
            on = jazzy.IsRadioOn();
            if (on)
            {
                jazzy.ScanDown();
            }
            else
            {
                printf("\nYou must turn the radio on before you can use the scan button!\n");

            }
            break;
        case kMenuQuit:
            break;
        default:
            printf("You have entered an invalid selection. Please make \n"
                "another selection.\n");
            break;

        }

        if ((choice != kMenuShowCurrentSettings) && (choice != kMenuQuit))
            jazzy.ShowCurrentSettings();

    } while (choice != kMenuQuit);

    printf("\nGoodbye!\n");
    return 0;


}