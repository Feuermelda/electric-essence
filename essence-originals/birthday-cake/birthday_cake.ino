const int ledPins[5] = { 5, 6, 9, 10, 11 };

const int buttonPin = 2;

const int soundPin = A0;

bool lastButtonState = HIGH;

bool burning = 0;
int candlesLit = 0;



void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(soundPin, INPUT);

  Serial.begin(9600);
}

void loop() {

  // candle lighting logic
  while (candlesLit < 5) {
    int buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);
    if (buttonState == LOW && lastButtonState == HIGH) {
      digitalWrite(ledPins[candlesLit], HIGH);
      candlesLit++;
      delay(500);
      if (candlesLit == 4) {
        burning = 1;
      }
    }
    lastButtonState = buttonState;
    delay(50);
  }

  while (burning) {
    // blowout & flickering logic
    int soundState = analogRead(soundPin);
    Serial.println(soundState);
    if (soundState > 87 && soundState < 400) {
      // intensity
      int intensity = map(soundState, 85, 400, 50, 175);

      // Flicker once
      for (int i = 0; i < 5; i++) {

        int bright = random(255 - intensity, 255);  // for bright flickering
        analogWrite(ledPins[i], bright);
      }
      delay(random(50, 100));  // short delay to simulate flicker

      for (int i = 0; i < 5; i++) {
        int dark = random(150 - intensity, 150);  // for dimmer flickering
        analogWrite(ledPins[i], dark);
      }
      delay(random(30, 80));  // wait a bit before next flicker
    }

    if (soundState >= 400) {
      for (int i = 0; i < 5; i++) {
        digitalWrite(ledPins[i], LOW);
        delay(50);
      }
      burning = 0;
      candlesLit = 0;
      lastButtonState = HIGH;
    }
  }
}
