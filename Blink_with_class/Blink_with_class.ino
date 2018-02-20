#include <Led.h>
#include <BlinkingLed.h>
#include <FadingLed.h>

Led led(13);
BlinkingLed bled(12, 250, 1000);
FadingLed fled(11, 2000, 1000);
Led *leds[] = { &led, &bled, &fled };

void setup() {
    for (auto elt : leds) {
        elt->begin();
    }
}

void loop() {
    for (auto elt : leds) {
        elt->update();
    }
}
