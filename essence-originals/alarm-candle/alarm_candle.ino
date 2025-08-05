const int ledPin = 13;
const int buttonPin = 8;

int pressCount = 0;
bool lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(ledPin, HIGH);

}

void loop() {
  
  int buttonState = digitalRead(buttonPin);
  
  
  if (buttonState == LOW && lastButtonState == HIGH) { // pressed down
  Serial.print("Button pressed\n");
  Serial.println(pressCount+1);
    pressCount++;
    if (pressCount >= 3){
        pressCount = 0;
        digitalWrite(ledPin, LOW);
        delay(10000);
        digitalWrite(ledPin, HIGH);
      } else {
    for (int i=0; i<3; i++) {
      digitalWrite(ledPin, LOW);
      delay(100);
      digitalWrite(ledPin, HIGH);
      delay(100);
    }
      }  
  } if (pressCount < 3) {
    digitalWrite(ledPin, HIGH);
  }
  lastButtonState = buttonState;
}
