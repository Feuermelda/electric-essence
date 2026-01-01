const int ledPin = 6;
const int motionPin = 8;
const int lightPin = A0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(motionPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int motionState = digitalRead(motionPin);
  int lightVal = analogRead(lightPin);

  Serial.print("Light: ");
  Serial.print(lightVal);
  Serial.print(" | Motion: ");
  Serial.println(motionState);

  // Trigger only if it's dark *and* motion is detected
  if (lightVal > 600 && motionState == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(2000); // stay on for 2 seconds
    digitalWrite(ledPin, LOW);
  }

  delay(100); // small cooldown
}
