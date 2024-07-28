/*
* FILE : PioneerCarRadio.cpp
* PROJECT : PROG1385 - Assignment #6
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-07-20
* DESCRIPTION :
*   This file contains the implementation of the PioneerCarRadio class. It provides
*   additional functionality specific to a car radio, including handling user input
*   through keystrokes. The class allows users to toggle power, adjust volume, scan
*   stations, switch bands, and manage presets using keyboard input.
*/
#include "PioneerCarRadio.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define ON_OFF       'o'
#define VOLUME_UP    '+'
#define VOLUME_DOWN  '_'
#define SCAN_UP      '='
#define SCAN_DOWN    '-'
#define SWITCH_BAND  'b'
#define CHOOSE_ONE   '1'
#define CHOOSE_TWO   '2'
#define CHOOSE_THREE '3'
#define CHOOSE_FOUR  '4'
#define CHOOSE_FIVE  '5'
#define SET_ONE      '!'
#define SET_TWO      '@'
#define SET_THREE    '#'
#define SET_FOUR     '$'
#define SET_FIVE     '%'
#define EXIT         'x'

PioneerCarRadio::PioneerCarRadio(void) : AmFmRadio(false)
{
    m_name = "Pioneer XS440";
}

/*
* FUNCTION : ~PioneerCarRadio (destructor)
* DESCRIPTION :
*   Print destruction.
* PARAMETERS :
*   None
* RETURNS :
*   None (destructor)
*/
PioneerCarRadio::~PioneerCarRadio()
{
    printf("Destroying %s Radio\n", GetName());
}

/*
* FUNCTION : GetName
* DESCRIPTION :
*   Retrieves the name of the PioneerCarRadio object.
* PARAMETERS :
*   None
* RETURNS :
*   const char* : A C-string representing the name of the radio.
*/
const char* PioneerCarRadio::GetName(void) const
{
    return m_name;
}

/*
* FUNCTION : HandleKeystroke
* DESCRIPTION :
*   Processes user keystrokes to interact with the radio, handling input
*   to control the radio functions such as changing stations, adjusting volume,
*   and toggling power.
* PARAMETERS :
*   None
* RETURNS :
*   void
*/
void PioneerCarRadio::ProcessUserKeyStroke(void)
{
    while(true)
    {
        system("cls");
        printf("%s\n", GetName());
        if (IsRadioOn())
        {
            printf("Radio is on\n");
            printf("Volume: %d\n", GetCurrentVolume());
            char band[3] = "";
            GetCurrentBand(band);
            Freqs presets[5] = {};
            GetRadioPresets(presets);
            if (strcmp("AM", band) == 0)
            {
                printf("Current Station: %5d %s\n", GetCurrentStation().AMFreq, band);
                printf("AM Buttons:\n");
                for (int i = 0; i < 5; ++i)
                {
                    printf("%d: %5d, ", i + 1, presets[i].AMFreq);
                }
                putchar('\n');
            }
            else
            {
                printf("Current Station: %6.1f %s\n", GetCurrentStation().FMFreq, band);
                printf("FM Buttons:\n");
                for (int j = 0; j < 5; ++j)
                {
                    printf("%d: %5.1f, ", j + 1, presets[j].FMFreq);
                }
                putchar('\n');
            }
        }
        else
        {
            printf("Radio is off\n");
        }

        int keystroke = _getch();

        switch (keystroke)
        {
        case ON_OFF:
            PowerToggle();
            break;
        case VOLUME_UP:
            if (IsRadioOn())
                SetVolume(GetCurrentVolume() + 1);
            break;
        case VOLUME_DOWN:
            if (IsRadioOn())
                SetVolume(GetCurrentVolume() - 1);
            break;
        case SCAN_UP:
            if (IsRadioOn())
                ScanUp();
            break;
        case SCAN_DOWN:
            if (IsRadioOn())
                ScanDown();
            break;
        case SWITCH_BAND:
            if (IsRadioOn())
                ToggleFrequency();
            break;
        case CHOOSE_ONE:
            if (IsRadioOn())
                SelectPresetButton(0);
            break;
        case CHOOSE_TWO:
            if (IsRadioOn())
                SelectPresetButton(1);
            break;
        case CHOOSE_THREE:
            if (IsRadioOn())
                SelectPresetButton(2);
            break;
        case CHOOSE_FOUR:
            if (IsRadioOn())
                SelectPresetButton(3);
            break;
        case CHOOSE_FIVE:
            if (IsRadioOn())
                SelectPresetButton(4);
            break;
        case SET_ONE:
            if (IsRadioOn())
                SetPresetButton(0);
            break;
        case SET_TWO:
            if (IsRadioOn())
                SetPresetButton(1);
            break;
        case SET_THREE:
            if (IsRadioOn())
                SetPresetButton(2);
            break;
        case SET_FOUR:
            if (IsRadioOn())
                SetPresetButton(3);
            break;
        case SET_FIVE:
            if (IsRadioOn())
                SetPresetButton(4);
            break;
        case EXIT:
            return;
        default:
            break;
        }
    }
}
