/*
* FILE : AmFmRadio.h
* PROJECT : PROG1385 - Assignment #3
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-06-05
* DESCRIPTION :
* This is a header file for the AmFmRadio class. It defines the structure and
* interface for a simulated AM/FM radio, including functionality for power
* control, frequency tuning, preset management, volume control, and display
* settings. The class provides methods to interact with the radio, change
* stations, set presets, adjust volume, and view current settings.
*/

#ifndef _AMFMRADIO_H
#define _AMFMRADIO_H

/*
* NAME : Freqs
* PURPOSE : The Freqs struct represents a radio frequency. This
*           struct is used within the AmFmRadio class to manage station
*           frequencies for both bands.
*/
struct Freqs
{
    int AMFreq;
    float FMFreq;
};


/*
* NAME : AmFmRadio
* PURPOSE : The AmFmRadio class models the behavior of a standard AM/FM radio.
*           It provides functionality for power control, band selection,
*           preset management, volume control, station tuning, and display settings.
*           The class allows users to interact with the radio, change stations,
*           set presets, adjust volume, and view current settings.
*/
class AmFmRadio
{
private:
    Freqs	button[5];
    Freqs	current_station;
    char	band[3];
    int		volume;
    int     previous_volume;
    bool	on;
    bool    display_output;

public:
    //sets the each button to the lowest frequency, sets the current station, sets the
    //frequency to AM, sets the volume to 0 and sets on to false
    AmFmRadio(bool on = false);
    
    //sets the each button to the presets, sets the current station, sets the
    //frequency to AM, sets the volume to 0
    AmFmRadio(bool on, Freqs preset[5]);
    
    //print destruction
    ~AmFmRadio();

    //sets on to true
    void PowerToggle();

    //returns a true if the radio is currently powered on, and false if the radio is in
    //the off position
    bool IsRadioOn();

    //toggles frequency between AM and FM and sets current station
    void ToggleBand();

    //sets button (radio preset) with current station by being passed a button number
    int SetPresetButton(int button_num);

    //sets current station to radio preset by being passed a button number
    int SelectPresetButton(int button_num);

    //sets volume
    int SetVolume();

    //sets volume with specify value
    int SetVolume(int volume);

    //shows volume, button settings, current station, AM or FM
    void ShowCurrentSettings();

    //changes frequency up in increments of .2 for FM, 10 for AM
    void ScanUp();

    //changes frequency up in decrements of .2 for FM, 10 for AM
    void ScanDown();

    //sets the current station to the specified frequency if valid
    bool SetCurrentStation(double station);
    
    //enables or disables the display output
    void SetDisplayOutput(bool display);

    //returns the current station frequency
    Freqs GetCurrentStation();

    //returns the current volume level
    int GetCurrentVolume();

    //retrieves the frequencies stored in all preset buttons
    void GetRadioPresets(Freqs presets[5]);

    //retrieves the current radio band (AM or FM)
    void GetCurrentBand(char band[3]);

    //returns true if display output is enabled, false otherwise
    bool GetDisplayOutput();
};
#endif