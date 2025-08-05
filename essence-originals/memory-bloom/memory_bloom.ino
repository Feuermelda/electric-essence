const int ledPin = 6;
const int lightPin = A0;
const int soundPin = A3;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightVal = analogRead(lightPin);
  Serial.print("Light: ", lightVal);
  int soundVal = analogRead(soundPin);
  Serial.println(" | Sound: ", soundVal); 

  if (lightVal < 500) {
    if (soundVal > 86) {
      digitalWrite(ledPin, HIGH);
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(100);

}
