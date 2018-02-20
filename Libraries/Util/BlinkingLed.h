#pragma once

#include "Led.h"

class BlinkingLed : public Led {
    public:
        BlinkingLed(const byte &pin, const unsigned long &timeOn, const unsigned long &timeOff);
        
        void update();
    private:
        unsigned long timeOn;
        unsigned long timeOff;
        unsigned long startTime;
};
