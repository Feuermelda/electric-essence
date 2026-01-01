const int buttonPin = 2;
const int ledPin = 13;

unsigned long pressStartTime = 0;
bool isPressing = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  int buttonState = digitalRead(buttonPin);

  // if button is just now being pressed
  if (buttonState == LOW && !isPressing) {
    
    pressStartTime = millis();
    isPressing = true;
  }
  // if button was pressed and now released
  else if (buttonState == HIGH && isPressing) {
    unsigned long pressDuration = millis() - pressStartTime;

    if (pressDuration < 500) {
      // short press = LED ON
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
    } else {
      // long press = blink LED
      for (int i = 0; i < 3; i++) {
        digitalWrite(ledPin, HIGH);
        delay(100);
        digitalWrite(ledPin, LOW);
        delay(100);
      }
    }

    // reset press state
    isPressing = false;
  }
}
