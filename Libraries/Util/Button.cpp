#include "Button.h"

Button::Button(const byte &pin) : pin(pin) {

}

void Button::begin() {
    pinMode(pin, INPUT);
}

void Button::update() {
    pressed = digitalRead(pin) == LOW;
}

bool Button::isPressed() {
    return pressed;
}
