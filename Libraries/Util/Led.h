#pragma once

#include <Arduino.h>

enum class LedMode { BLINK, FADE };

class Led {
    public:
        Led(const byte &pin, const LedMode &mode, const unsigned long &timeOn, const unsigned long &timeOff);
        
        void begin();
        void update();
    private:
        byte pin;
        LedMode mode;
        unsigned long timeOn;
        unsigned long timeOff;
        unsigned long startTime;
        bool fadeIn;

        void blink(const unsigned long &now, const unsigned long &elapsed);
        void fade(const unsigned long &now, const unsigned long &elapsed);
};

