#include "Led.h"

Led::Led(const byte &pin)
    : pin(pin), stateOn(true) {
}

void Led::begin() {
    pinMode(pin, OUTPUT);
}

void Led::update() {
    if (stateOn) switchOn(); else switchOff();
}

void Led::switchOn() {
    digitalWrite(pin, HIGH);
    stateOn = true;
}

void Led::switchOff() {
    digitalWrite(pin, LOW);
    stateOn = false;
}

bool Led::isOn() {
    return stateOn;
}
