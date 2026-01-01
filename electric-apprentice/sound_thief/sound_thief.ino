const int ledPin = 13;
const int soundPin = A0;
bool triggered = false;

void setup() {
  //pinMode(soundPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int soundState = analogRead(soundPin);
  Serial.print("Sound state: ");
  Serial.println(soundState);

  if (soundState >= 85 && !triggered) {
    triggered = true;
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
  }

  if (soundState < 85) {
    triggered = false; // reset so we can trigger again
  }

  delay(50); // small debounce/cooldown

}
