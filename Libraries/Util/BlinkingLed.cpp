#include "BlinkingLed.h"

BlinkingLed::BlinkingLed(const byte &pin, const unsigned long &timeOn, const unsigned long &timeOff)
    : Led(pin), timeOn(timeOn), timeOff(timeOff) {
    startTime = millis();
}

void BlinkingLed::update() {
    if (!isOn()) return;
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
