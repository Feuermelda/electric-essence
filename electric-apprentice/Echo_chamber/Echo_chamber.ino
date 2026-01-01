const int ledPin = 6;
const int motionPin = 8;
const int soundPin = A0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(motionPin, INPUT);
  pinMode(soundPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  int motionState = digitalRead(motionPin);
  int soundState = analogRead(soundPin);
  Serial.println(motionState);
  Serial.println(soundState);

  if ((motionState == HIGH) && (soundState > 85)) {
    digitalWrite(ledPin, HIGH);
    delay(50);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
