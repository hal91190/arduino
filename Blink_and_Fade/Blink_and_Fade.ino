const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  fade_in(5);
  blink(5, 500);
  fade_out(10);
}

void blink(byte repetition, int freq) {
  for (byte i = 0; i < repetition; ++i) {
    analogWrite(ledPin, 255);
    delay(freq);
    analogWrite(ledPin, 0);
    delay(freq);
  }
}

void fade_in(byte duration_in_s) {
  int delay_in_ms = duration_in_s * 1000 / 255;
  for (byte i = 0; i < 255; ++i) {
    analogWrite(ledPin, i);
    delay(delay_in_ms);
  }
}

void fade_out(byte duration_in_s) {
  int delay_in_ms = duration_in_s * 1000 / 255;
  for (byte i = 255; i > 0; --i) {
    analogWrite(ledPin, i);
    delay(delay_in_ms);
  }
}

