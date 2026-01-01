const int buttonPin = 2;
const int ledPin = 13;
bool ledState = false;
bool lastButtonState = HIGH;


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

 
}

void loop() {
  bool buttonState = digitalRead(buttonPin);



  if (buttonState == LOW && lastButtonState == HIGH) { // button was just pressed (new press!)
    ledState = !ledState; // flip state
    
    
  }
   digitalWrite(ledPin, ledState ? HIGH : LOW);

  lastButtonState = buttonState;

  delay(50);
}
