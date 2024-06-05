//AmFmRadio.h

#ifndef _AMFMRADIO_H
#define _AMFMRADIO_H

struct Freqs
{
    int AMFreq;
    float FMFreq;
};

class AmFmRadio
{
private:
    Freqs	button[5];
    double	current_station;
    char	band[3];
    int		volume;
    bool	on;

public:
    //sets the each button to the lowest frequency, sets the current station, sets the
    //frequency to AM, sets the volume to 0 and sets on to false
    AmFmRadio(bool on = false);
    AmFmRadio(bool on, Freqs preset[5]);
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

    //shows volume, button settings, current station, AM or FM
    void ShowCurrentSettings();

    //changes frequency up in increments of .2 for FM, 10 for AM
    void ScanUp();

    void ScanDown();

};
#endif