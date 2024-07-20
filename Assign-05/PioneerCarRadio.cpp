#include "PioneerCarRadio.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PioneerCarRadio::Display(void)
{
    printf("Pioneer XS440\n");
    if (IsRadioOn())
    {
        printf("Radio is on\n");

        printf("Volume: %d\n", GetCurrentVolume());
        char band[3] = "";
        GetCurrentBand(band);
        if (strcmp("AM", band) == 0)
            printf("Current Station: %d %s\n", GetCurrentStation().AMFreq, band);
        else
            printf("Current Station: %.1f %s\n", GetCurrentStation().FMFreq, band);
        printf("AM Buttons:\n");
        Freqs presets[5] = {};
        GetRadioPresets(presets);
        for (int i = 0; i < 5; ++i)
        {
            printf("%d: %6d ", i + 1, presets[i].AMFreq);
        }
        putchar('\n');
        printf("FM Buttons:\n");
        for (int j = 0; j < 5; ++j)
        {
            printf("%d: %6.1f ", j + 1, presets[j].FMFreq);
        }
        putchar('\n');
    }
    else
    {
        printf("Radio is off\n");
    }
}
