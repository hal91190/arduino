const int ledPin = 9;
const int buttonPin = 2;
int action = 0; // blink by default
int lastAction = 0;

void blink(byte repetition, int freq);
void fade_in(byte duration_in_s);
void fade_out(byte duration_in_s);

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonValue = digitalRead(buttonPin);
  Serial.println(buttonValue);
  if (buttonValue == LOW) {
    action = 1 - action;
  }
  if (action) {
    fade_in(1);
    fade_out(1);
  } else {
    blink(1, 250);
  }
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

