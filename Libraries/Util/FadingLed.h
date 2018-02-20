#pragma once

#include <Led.h>

class FadingLed : public Led {
    public:
        FadingLed(const byte &pin, const unsigned long &timeOn, const unsigned long &timeOff);
        
        void update();
    private:
        unsigned long timeOn;
        unsigned long timeOff;
        unsigned long startTime;
        bool fadeIn;
};
