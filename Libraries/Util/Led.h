#pragma once

class Led {
    public:
        Led(const byte &pin, const unsigned long &timeOn, const unsigned long &timeOff);
        
        void begin();
        void update();
    private:
        byte pin;
        unsigned long timeOn;
        unsigned long timeOff;
        unsigned long startTime;
};

