#include <Led.h>
#include <BlinkingLed.h>
#include <FadingLed.h>
#include <Button.h>

#define QUANTUM 250

Led led(13);
BlinkingLed bled(12, 250, 1000);
FadingLed fled(11, 2000, 1000);
const byte NB_LEDS = 3;
Led *leds[NB_LEDS] = { &led, &bled, &fled };
byte activeLed = 0;

Button button(2);

void setup() {
    for (auto elt : leds) {
        elt->begin();
    }
    button.begin();
}

void loop() {
    button.update();
    if (button.isPressed()) {
        if (leds[activeLed]->isOn()) leds[activeLed]->switchOff(); else leds[activeLed]->switchOn();
        delay(QUANTUM);
        activeLed = (activeLed + 1) % NB_LEDS;
    }
    for (auto elt : leds) {
        elt->update();
    }
}
