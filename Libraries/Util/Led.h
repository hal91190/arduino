#pragma once

#include <Arduino.h>

class Led {
    public:
        Led(const byte &pin);
        
        virtual void begin();
        virtual void update();

        void switchOn();
        void switchOff();
        bool isOn();
    protected:
        byte pin;
        bool stateOn;
};
