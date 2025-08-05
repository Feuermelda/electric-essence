const int ledPin = 6;
const int lightPin = A0;
const int soundPin = A3;

bool isBlooming = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

   int lightVal = analogRead(lightPin);
  Serial.print("Light: ", lightVal);
  int soundVal = analogRead(soundPin);
  Serial.println(" | Sound: ", soundVal);

  // trigger: dark + sound
  if (!isBlooming && lightVal < 500 && soundVal > 86) {
    isBlooming = true;
  }

  // reset: sunrise
  if (isBlooming && lightVal > 700) {
    isBlooming = false;
  }

  digitalWrite(ledPin, isBlooming ? HIGH : LOW);

  delay(100);
}
