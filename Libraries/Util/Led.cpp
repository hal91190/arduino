#include <Arduino.h>

#include "Led.h"

Led::Led(const byte &pin, const unsigned long &timeOn, const unsigned long &timeOff)
    : pin(pin), timeOn(timeOn), timeOff(timeOff) {
    startTime = millis();
}

void Led::begin() {
    pinMode(pin, OUTPUT);
    startTime = millis();
}

void Led::update() {
    unsigned long now = millis();
    unsigned long elapsed = now - startTime;
    bool ledOn = digitalRead(pin) == HIGH;
    if (ledOn && elapsed > timeOn) {
        digitalWrite(pin, LOW);
        startTime = millis();
    }
    if (!ledOn && elapsed > timeOff) {
        digitalWrite(pin, HIGH);
        startTime = millis();
    }
}
