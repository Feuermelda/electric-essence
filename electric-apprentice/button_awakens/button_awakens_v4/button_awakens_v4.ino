const int buttonPin = 2;
const int ledPin = 13;
const int greenLedPin = 8;

unsigned long lastPressTime = 0;
int pressCount = 0;
bool lastButtonState = HIGH;
const int comboTimeout = 1000;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  digitalWrite(greenLedPin, LOW);

  Serial.begin(9600);
}

void loop() {
  
  if (pressCount == 1 && (millis() - lastPressTime > comboTimeout)) {
    // too late - combo failed
   for (int i = 0; i<3; i++) {
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
      delay(200);
      // too slow, reset count;
    }
    pressCount = 0;
    delay(500);
      
    }
  int buttonState = digitalRead(buttonPin);
  // detect a new press (LOW now, HIGH before)
  if (buttonState == LOW && lastButtonState == HIGH) {
    unsigned long now = millis();
   
    if (now - lastPressTime <= 500) {
      pressCount++;
     
    } else {
      
      pressCount = 0; 
    }
  
    lastPressTime = now;
  }
  // trigger secret combo
  if (pressCount == 2) {
    digitalWrite(greenLedPin, HIGH);
    delay(2000);
    digitalWrite(greenLedPin, LOW);
    pressCount = 0;
    lastPressTime = 0;
  }
  lastButtonState = buttonState;
}
