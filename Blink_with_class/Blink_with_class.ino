#include <Led.h>

Led led(11, LedMode::FADE, 1000, 1000);

void setup() {
    led.begin();
}

void loop() {
    led.update();
}
