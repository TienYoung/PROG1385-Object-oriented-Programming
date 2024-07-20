/*
* FILE : AmFmRadio.cpp
* PROJECT : PROG1385 - Assignment #3
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-06-05
* DESCRIPTION :
* This file contains the implementation of the AmFmRadio class. It provides
* functionality for a simulated AM/FM radio, including power control,
* frequency tuning, preset management, volume control, and display settings.
* The class allows users to toggle power, change bands, set and select presets,
* adjust volume, scan frequencies, and retrieve current radio settings.
* It also includes constructors for initializing the radio with default
* or custom preset frequencies.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AmFmRadio.h"

template<typename T>
inline T clamp(T x, T min, T max)
{
    return x < min ? min : (x > max ? max : x);
}

/*
* FUNCTION : AmFmRadio (constructor)
* DESCRIPTION :
*   Initializes a new AmFmRadio object. Sets each button to the lowest frequency,
*   sets the current station, sets the band to AM, sets the volume to 0,
*   and sets the power state.
* PARAMETERS :
*   bool on : initial power state of the radio (default is false)
* RETURNS :
*   None (constructor)
*/
AmFmRadio::AmFmRadio(bool on /*= false*/)
{
    for (int i = 0; i < 5; ++i)
    {
        button[i].AMFreq = AM_MIN;
    }
    for (int j = 0; j < 5; ++j)
    {
        button[j].FMFreq = FM_MIN;
    }
    current_station.AMFreq = AM_MIN;
    current_station.FMFreq = FM_MIN;
    strcpy_s(band, sizeof(band), "AM");
    volume = 0;
    previous_volume = 0;
    this->on = on;
    display_output = false;
}

/*
* FUNCTION : AmFmRadio (constructor with presets)
* DESCRIPTION :
*   Initializes a new AmFmRadio object with preset stations. Sets the power state
*   and initializes the preset buttons with the provided frequencies.
* PARAMETERS :
*   bool on : initial power state of the radio
*   Freqs preset[5] : array of 5 preset frequencies
* RETURNS :
*   None (constructor)
*/
AmFmRadio::AmFmRadio(bool on, Freqs preset[5])
{
    for (int i = 0; i < 5; ++i)
    {
        button[i].AMFreq = clamp(preset[i].AMFreq, AM_MIN, AM_MAX);
    }
    for (int j = 0; j < 5; ++j)
    {
        button[j].FMFreq = clamp(preset[j].FMFreq, FM_MIN, FM_MAX);
    }
    current_station.AMFreq = AM_MIN;
    current_station.FMFreq = FM_MIN;
    strcpy_s(band, sizeof(band), "AM");
    volume = 0;
    previous_volume = 0;
    this->on = on;
    display_output = false;
}

/*
* FUNCTION : ~AmFmRadio (destructor)
* DESCRIPTION :
*   Cleans up any resources used by the AmFmRadio object.
* PARAMETERS :
*   None
* RETURNS :
*   None (destructor)
*/
AmFmRadio::~AmFmRadio()
{
    printf("Destroying AmFmRadio\n");
}

/*
* FUNCTION : PowerToggle
* DESCRIPTION :
*   Toggles the power state of the radio (on/off).
* PARAMETERS :
*   None
* RETURNS :
*   void
*/
void AmFmRadio::PowerToggle(void)
{
    if (on == false)
    {
        on = true;
        volume = previous_volume;
    }
    else
    {
        previous_volume = volume;
        volume = 0;
        on = false;
    }
}

/*
* FUNCTION : IsRadioOn
* DESCRIPTION :
*   Checks if the radio is currently powered on.
* PARAMETERS :
*   None
* RETURNS :
*   bool : true if the radio is on, false if it's off
*/
bool AmFmRadio::IsRadioOn(void) const
{
    return on;
}

/*
* FUNCTION : SetVolume (no parameters)
* DESCRIPTION :
*   Sets the volume of the radio (implementation specific).
* PARAMETERS :
*   None
* RETURNS :
*   int : new volume level or status code
*/
int AmFmRadio::SetVolume(void)
{
    if (!on) return VolumeStatus::MUTE;

    char buf[20] = "";

    printf("\nEnter the volume level (0 - 100). ");
    fgets(buf, sizeof buf, stdin);
    volume = atoi(buf);

    return SetVolume(volume);
}

/*
* FUNCTION : SetVolume (with parameter)
* DESCRIPTION :
*   Sets the volume of the radio to a specific level.
* PARAMETERS :
*   int volume : the desired volume level
* RETURNS :
*   int : new volume level or status code
*/
int AmFmRadio::SetVolume(int volume)
{
    if (!on) return VolumeStatus::MUTE;

    this->volume = volume;
    if (this->volume < VOL_MIN) //if user enters volume less than 0, volume = 0
    {
        this->volume = VOL_MIN;
        return VolumeStatus::MUTE;
    }

    if (this->volume > VOL_MAX) //if user enters volume greater than 100, volume = 100
    {
        this->volume = VOL_MAX;
        return VolumeStatus::FULL;
    }

    return VolumeStatus::OK;
}

/*
* FUNCTION : ToggleBand
* DESCRIPTION :
*   Switches the radio band between AM and FM and sets the current station accordingly.
* PARAMETERS :
*   None
* RETURNS :
*   void
*/
void AmFmRadio::ToggleBand(void)
{
    if (strcmp(band, "AM") == 0)
    {
        strcpy_s(band, sizeof(band), "FM");
    }
    else
    {
        strcpy_s(band, sizeof(band), "AM");
    }
}

/*
* FUNCTION : SetPresetButton
* DESCRIPTION :
*   Sets a preset button with the current station frequency.
* PARAMETERS :
*   int button_num : the number of the preset button to set (1-5)
* RETURNS :
*   int : status code (implementation specific)
*/
int AmFmRadio::SetPresetButton(int button_num)
{
    if ((button_num >= 0) && (button_num <= 4))
    {
        if (strcmp("AM", band) == 0)
        {
            button[button_num].AMFreq = GetCurrentStation().AMFreq;
        }
        else
        {
            button[button_num].FMFreq = GetCurrentStation().FMFreq;
        }
        return 1;

    }
    return 0;

}

/*
* FUNCTION : SelectPresetButton
* DESCRIPTION :
*   Tunes the radio to the station stored in the specified preset button.
* PARAMETERS :
*   int button_num : the number of the preset button to select (1-5)
* RETURNS :
*   int : status code (implementation specific)
*/
int AmFmRadio::SelectPresetButton(int button_num)
{
    if ((button_num >= 0) && (button_num <= 4))
    {
        if (strcmp("AM", band) == 0)
        {
            SetCurrentStation(button[button_num].AMFreq);
        }
        else
        {
            SetCurrentStation(button[button_num].FMFreq);
        }

        return 1;
    }
    return 0;


}

/*
* FUNCTION : ShowCurrentSettings
* DESCRIPTION :
*   Displays the current settings of the radio, including volume,
*   preset buttons, current station, and band (AM/FM).
* PARAMETERS :
*   None
* RETURNS :
*   void
*/
void AmFmRadio::ShowCurrentSettings(void)
{

    if (on == true)
    {
        printf("\n\nRadio is on. \n");
    }
    else
    {
        printf("\n\nRadio is off. \n");
    }

    printf("\nRadio Band: %s\n", band);
    printf("Volume: %d\n", volume);
    if (strcmp("AM", band) == 0)
    {
        printf("Current Station: %d %s\n", GetCurrentStation().AMFreq, band);
    }
    else
    {
        printf("Current Station: %.1f %s\n", GetCurrentStation().FMFreq, band);
    }
    printf("AM Button Settings: ");
    for (int i = 0; i < 5; ++i)
    {
        printf("%d) %6d ", i + 1, button[i].AMFreq);
    }

    printf("\nFM Button Settings: ");
    for (int j = 0; j < 5; ++j)
    {
        printf("%d) %6.1f ", j + 1, button[j].FMFreq);
    }
}

/*
* FUNCTION : ScanUp
* DESCRIPTION :
*   Increases the current station frequency (.2 MHz for FM, 10 kHz for AM).
* PARAMETERS :
*   None
* RETURNS :
*   void
*/
void AmFmRadio::ScanUp(void)
{
    if (strcmp("AM", band) == 0)
    {
        //if current_station is 1700, the current_station becomes 530
        if (current_station.AMFreq == AM_MAX)
        {
            current_station.AMFreq = AM_MIN;
        }
        else
        {
            current_station.AMFreq = current_station.AMFreq + AM_STEP;
        }
        if (display_output)
            printf("\nCurrent station: %d %s\n", current_station.AMFreq, band);
    }
    else
    {
        //if the current_station is 107.9, the current_station becomes 87.9
        //Note: car radios jump .2 for the FM. That's how it's modeled here.
        if (current_station.FMFreq >= FM_MAX)
        {
            current_station.FMFreq = FM_MIN;
        }
        else
        {
            current_station.FMFreq = current_station.FMFreq + FM_STEP;
        }
        if (display_output)
            printf("\nCurrent station: %f %s\n", current_station.FMFreq, band);
    }
}

/*
* FUNCTION : ScanDown
* DESCRIPTION :
*   Decreases the current station frequency (.2 MHz for FM, 10 kHz for AM).
* PARAMETERS :
*   None
* RETURNS :
*   void
*/
void AmFmRadio::ScanDown(void)
{
    if (strcmp("AM", band) == 0)
    {
        //if current_station is 530, the current_station becomes 1700
        if (current_station.AMFreq == AM_MIN)
        {
            current_station.AMFreq = AM_MAX;
        }
        else
        {
            current_station.AMFreq = current_station.AMFreq - AM_STEP;
        }
        if (display_output)
            printf("\nCurrent station: %d %s\n", current_station.AMFreq, band);
    }
    else
    {
        //if the current_station is 87.9, the current_station becomes 107.9
        //Note: car radios jump .2 for the FM. That's how it's modeled here.
        if (current_station.FMFreq <= FM_MIN)
        {
            current_station.FMFreq = FM_MAX;
        }
        else
        {
            current_station.FMFreq = current_station.FMFreq - FM_STEP;
        }
        if (display_output)
            printf("\nCurrent station: %f %s\n", current_station.FMFreq, band);
    }
}

/*
* FUNCTION : SetCurrentStation
* DESCRIPTION :
*   Sets the radio to a specific station frequency.
* PARAMETERS :
*   double station : the desired station frequency
* RETURNS :
*   bool : true if successful, false otherwise
*/
bool AmFmRadio::SetCurrentStation(double station)
{
    if (strcmp("AM", band) == 0)
    {
        if (station >= AM_MIN && station <= AM_MAX)
        {
            current_station.AMFreq = static_cast<int>(station);
            return true;
        }
    }
    else
    {
        if (station >= FM_MIN && station <= FM_MAX)
        {
            current_station.FMFreq = station;
            return true;
        }
    }

    return false;
}

/*
* FUNCTION : SetDisplayOutput
* DESCRIPTION :
*   Sets whether the radio should display output or not.
* PARAMETERS :
*   bool display : true to enable display output, false to disable
* RETURNS :
*   void
*/
void AmFmRadio::SetDisplayOutput(bool display)
{
    display_output = display;
}

/*
* FUNCTION : GetCurrentStation
* DESCRIPTION :
*   Retrieves the current station frequency.
* PARAMETERS :
*   None
* RETURNS :
*   Freqs : the current station frequency
*/
Freqs AmFmRadio::GetCurrentStation(void) const
{
    return current_station;
}

/*
* FUNCTION : GetCurrentVolume
* DESCRIPTION :
*   Retrieves the current volume level of the radio.
* PARAMETERS :
*   None
* RETURNS :
*   int : the current volume level
*/
int AmFmRadio::GetCurrentVolume(void) const
{
    return volume;
}

/*
* FUNCTION : GetRadioPresets
* DESCRIPTION :
*   Retrieves the frequencies stored in all preset buttons.
* PARAMETERS :
*   Freqs presets[5] : array to store the preset frequencies
* RETURNS :
*   void
*/
void AmFmRadio::GetRadioPresets(Freqs presets[5]) const
{
    if (presets == nullptr)
        return;

    memcpy(presets, button, sizeof(Freqs) * 5);
}

/*
* FUNCTION : GetCurrentBand
* DESCRIPTION :
*   Retrieves the current radio band (AM or FM).
* PARAMETERS :
*   char band[3] : array to store the band string
* RETURNS :
*   void
*/
void AmFmRadio::GetCurrentBand(char band[3]) const
{
    if (band == nullptr) 
        return;

    band[0] = this->band[0];
    band[1] = this->band[1];
    band[2] = this->band[2];
}

/*
* FUNCTION : GetDisplayOutput
* DESCRIPTION :
*   Retrieves the current display output setting.
* PARAMETERS :
*   None
* RETURNS :
*   bool : true if display output is enabled, false otherwise
*/
bool AmFmRadio::GetDisplayOutput(void) const
{
    return display_output;
}

