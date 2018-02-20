#include "Led.h"

Led::Led(const byte &pin, const LedMode &mode, const unsigned long &timeOn, const unsigned long &timeOff)
    : pin(pin), mode(mode), timeOn(timeOn), timeOff(timeOff), fadeIn(true) {
    startTime = millis();
}

void Led::begin() {
    pinMode(pin, OUTPUT);
    startTime = millis();
}

void Led::update() {
    unsigned long now = millis();
    unsigned long elapsed = now - startTime;
    switch (mode) {
        default:
        case LedMode::BLINK:
            blink(now, elapsed);
            break;
        case LedMode::FADE:
            fade(now, elapsed);
            break;
    }
}

void Led::blink(const unsigned long &now, const unsigned long &elapsed) {
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

void Led::fade(const unsigned long &now, const unsigned long &elapsed) {
    char buffer[500];
    const byte alwaysOn = 255;
    if (fadeIn) { // Fade in
        if (elapsed >= timeOn) {
            fadeIn = false;
            startTime = millis();
        } else {
            sprintf(buffer, "Fade in : %d / %d * %d = %d", elapsed, timeOn, alwaysOn, static_cast<double>(elapsed) / timeOn * alwaysOn);
            Serial.println(buffer);
            analogWrite(pin, static_cast<double>(elapsed) / timeOn * alwaysOn);
        }
    } else { // Fade out
        if (elapsed >= timeOff) {
            fadeIn = true;
            startTime = millis();
        } else {
            sprintf(buffer, "Fade out : (1 - %d / %d) * %d = %d", elapsed, timeOff, alwaysOn, (1 - static_cast<double>(elapsed) / timeOff) * alwaysOn);
            Serial.println(buffer);
            analogWrite(pin, (1 - static_cast<double>(elapsed) / timeOff) * alwaysOn);
        }
    }
}
