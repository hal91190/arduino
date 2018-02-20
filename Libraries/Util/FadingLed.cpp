#include "FadingLed.h"

FadingLed::FadingLed(const byte &pin, const unsigned long &timeOn, const unsigned long &timeOff)
    : Led(pin), timeOn(timeOn), timeOff(timeOff), fadeIn(true) {
    startTime = millis();
}

void FadingLed::update() {
    unsigned long now = millis();
    unsigned long elapsed = now - startTime;
    const byte alwaysOn = 255;
    if (fadeIn) { // Fade in
        if (elapsed >= timeOn) {
            fadeIn = false;
            startTime = millis();
        } else {
            analogWrite(pin, static_cast<double>(elapsed) / timeOn * alwaysOn);
        }
    } else { // Fade out
        if (elapsed >= timeOff) {
            fadeIn = true;
            startTime = millis();
        } else {
            analogWrite(pin, (1 - static_cast<double>(elapsed) / timeOff) * alwaysOn);
        }
    }
}
