#pragma once

#include <Arduino.h>

class Button {
    public:
        Button(const byte &pin);

        void begin();
        void update();
        bool isPressed();
    private:
        byte pin;
        bool pressed;
};
