//AmFmRadio.cpp
// This header comment is quite inadequate and should be replaced.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AmFmRadio.h"


AmFmRadio::AmFmRadio(bool on /*= false*/)
{
    for (int i = 0; i < 5; ++i)
    {
        button[i].AMFreq = 530;
    }
    for (int j = 0; j < 5; ++j)
    {
        button[j].FMFreq = 87.9f;
    }
    current_station.AMFreq = 530;
    current_station.FMFreq = 87.9f;
    strcpy_s(band, sizeof(band), "AM");
    volume = 0;
    previous_volume = 0;
    this->on = on;
    display_output = false;
}

AmFmRadio::AmFmRadio(bool on, Freqs preset[5])
{
    for (int i = 0; i < 5; ++i)
    {
        button[i].AMFreq = preset[i].AMFreq;
    }
    for (int j = 0; j < 5; ++j)
    {
        button[j].FMFreq = preset[j].FMFreq;
    }
    current_station.AMFreq = 530;
    current_station.FMFreq = 87.9f;
    strcpy_s(band, sizeof(band), "AM");
    volume = 0;
    previous_volume = 0;
    this->on = on;
    display_output = false;
}

AmFmRadio::~AmFmRadio()
{
    printf("Destroying AmFmRadio\n");
}

void AmFmRadio::PowerToggle()
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

bool AmFmRadio::IsRadioOn()
{
    return on;
}

int AmFmRadio::SetVolume()
{
    char buf[20] = "";

    printf("\nEnter the volume level (0 - 100). ");
    fgets(buf, sizeof buf, stdin);
    volume = atoi(buf);

    if (volume < 0) //if user enters volume less than 0, volume = 0
    {
        volume = 0;
        return 0;
    }

    if (volume > 100) //if user enters volume greater than 100, volume = 100
    {
        volume = 100;
        return 2;
    }
    return 1;


}

int AmFmRadio::SetVolume(int volume)
{
    this->volume = volume;
    if (this->volume < 0) //if user enters volume less than 0, volume = 0
    {
        this->volume = 0;
        return 0;
    }

    if (this->volume > 100) //if user enters volume greater than 100, volume = 100
    {
        this->volume = 100;
        return 2;
    }

    return 1;
}

void AmFmRadio::ToggleBand()
{
    if (strcmp(band, "AM") == 0)
    {
        strcpy_s(band, sizeof(band), "FM");
        //current_station = 87.9;
    }
    else
    {
        strcpy_s(band, sizeof(band), "AM");
        //current_station = 530;
    }
}

int AmFmRadio::SetPresetButton(int button_num)
{
    if ((button_num >= 0) && (button_num <= 4))
    {
        if (strcmp("AM", band) == 0)
        {
            button[button_num].AMFreq = current_station.AMFreq;
        }
        else
        {
            button[button_num].FMFreq = current_station.FMFreq;
        }
        return 1;

    }
    return 0;

}

int AmFmRadio::SelectPresetButton(int button_num)
{
    if ((button_num >= 0) && (button_num <= 4))
    {
        if (strcmp("AM", band) == 0)
        {
            current_station.AMFreq = button[button_num].AMFreq;
        }
        else
        {
            current_station.FMFreq = button[button_num].FMFreq;
        }

        return 1;
    }
    return 0;


}

void AmFmRadio::ShowCurrentSettings()
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
        printf("Current Station: %d %s\n", current_station.AMFreq, band);
    }
    else
    {
        printf("Current Station: %.1f %s\n", current_station.FMFreq, band);
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

void AmFmRadio::ScanUp()
{
    if (strcmp("AM", band) == 0)
    {
        //if current_station is 1700, the current_station becomes 530
        if (current_station.AMFreq == 1700)
        {
            current_station.AMFreq = 530;
        }
        else
        {
            current_station.AMFreq = current_station.AMFreq + 10;
        }
        if (display_output)
            printf("\nCurrent station: %d %s\n", current_station.AMFreq, band);
    }
    else
    {
        //if the current_station is 107.9, the current_station becomes 87.9
        //Note: car radios jump .2 for the FM. That's how it's modeled here.
        if (current_station.FMFreq >= 107.9)
        {
            current_station.FMFreq = 87.9f;
        }
        else
        {
            current_station.FMFreq = current_station.FMFreq + .2f;
        }
        if (display_output)
            printf("\nCurrent station: %f %s\n", current_station.FMFreq, band);
    }
}

void AmFmRadio::ScanDown()
{
    if (strcmp("AM", band) == 0)
    {
        //if current_station is 530, the current_station becomes 1700
        if (current_station.AMFreq == 530)
        {
            current_station.AMFreq = 1700;
        }
        else
        {
            current_station.AMFreq = current_station.AMFreq - 10;
        }
        if (display_output)
            printf("\nCurrent station: %d %s\n", current_station.AMFreq, band);
    }
    else
    {
        //if the current_station is 87.9, the current_station becomes 107.9
        //Note: car radios jump .2 for the FM. That's how it's modeled here.
        if (current_station.FMFreq <= 87.9f)
        {
            current_station.FMFreq = 107.9f;
        }
        else
        {
            current_station.FMFreq = current_station.FMFreq - .2f;
        }
        if (display_output)
            printf("\nCurrent station: %f %s\n", current_station.FMFreq, band);
    }
}

bool AmFmRadio::SetCurrentStation(double station)
{
    if (strcmp("AM", band) == 0)
    {
        if (station >= 530 && station <= 1700)
        {
            current_station.AMFreq = static_cast<int>(station);
            return true;
        }
    }
    else
    {
        if (station >= 87.9 && station <= 107.9)
        {
            current_station.FMFreq = static_cast<float>(station);
            return true;
        }
    }

    return false;
}

void AmFmRadio::SetDisplayOutput(bool display)
{
    display_output = display;
}

Freqs AmFmRadio::GetCurrentStation()
{
    return current_station;
}

int AmFmRadio::GetCurrentVolume()
{
    return volume;
}

void AmFmRadio::GetRadioPresets(Freqs presets[5])
{
    if (presets == nullptr)
        return;

    memcpy(presets, button, sizeof(Freqs) * 5);
}

void AmFmRadio::GetCurrentBand(char band[3])
{
    if (band == nullptr) 
        return;

    band[0] = this->band[0];
    band[1] = this->band[1];
    band[2] = this->band[2];
}

bool AmFmRadio::GetDisplayOutput()
{
    return display_output;
}

