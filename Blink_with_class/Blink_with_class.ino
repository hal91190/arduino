#include <Led.h>

Led led(13, 500, 1000);

void setup() {
    led.begin();
}

void loop() {
    led.update();
}
