/*
* FILE : AmFmRadio.h
* PROJECT : PROG1385 - Assignment #5
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-07-20
* DESCRIPTION :
* This is a header file for the AmFmRadio class. It defines the structure and
* interface for a simulated AM/FM radio, including functionality for power
* control, frequency tuning, preset management, volume control, and display
* settings. The class provides methods to interact with the radio, change
* stations, set presets, adjust volume, and view current settings.
*/

#ifndef _AMFMRADIO_H
#define _AMFMRADIO_H

enum VolumeStatus{ MUTE = 0, OK = 1, FULL = 2 };

enum class BandMod { AM, FM };

/*
* NAME : Freqs
* PURPOSE : The Freqs struct represents a radio frequency. This
*           struct is used within the AmFmRadio class to manage station
*           frequencies for both bands.
*/
struct Freqs
{
    int AMFreq;
    double FMFreq;
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
protected:
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
    virtual ~AmFmRadio(void);

    //sets on to true
    void PowerToggle(void);

    //returns a true if the radio is currently powered on, and false if the radio is in
    //the off position
    bool IsRadioOn(void) const;

    //toggles frequency between AM and FM and sets current station
    virtual void ToggleFrequency(void);

    //sets button (radio preset) with current station by being passed a button number
    int SetPresetButton(int button_num);

    //sets current station to radio preset by being passed a button number
    int SelectPresetButton(int button_num);

    //sets volume
    int SetVolume(void);

    //sets volume with specify value
    int SetVolume(int volume);

    //shows volume, button settings, current station, AM or FM
    void ShowCurrentSettings(void);

    //changes frequency up in increments of .2 for FM, 10 for AM
    virtual void ScanUp(void);

    //changes frequency up in decrements of .2 for FM, 10 for AM
    virtual void ScanDown(void);

    //sets the current station to the specified frequency if valid
    bool SetCurrentStation(double station);
    
    //enables or disables the display output
    void SetDisplayOutput(bool display);

    //returns the current station frequency
    Freqs GetCurrentStation(void) const;

    //returns the current volume level
    int GetCurrentVolume(void) const;

    //retrieves the frequencies stored in all preset buttons
    void GetRadioPresets(Freqs presets[5]) const;

    //retrieves the current radio band (AM or FM)
    void GetCurrentBand(char band[3]) const;

    //returns true if display output is enabled, false otherwise
    bool GetDisplayOutput(void) const;
};
#endif