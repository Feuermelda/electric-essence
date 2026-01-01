const int buttonPin = 2;
const int ledPin = 13;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // uses internal pull-up resistor
  pinMode(ledPin, OUTPUT); 

}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) { // button pressed (LOW due to pullup)
    digitalWrite(ledPin, HIGH); // turn LED on
  } else {
    digitalWrite(ledPin, LOW); // turn LED off
  }

}
