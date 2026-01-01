const int ledPin = 6;
const int lightPin = A0;
const int echoPin = 10;
const int trigPin = 8;

long duration;
int distance;

const int darkThresh = 600; // room considered "dark" if lightVal > 10
const int nearThresh_cm = 10; // <= 10cm = fully bright
const int farThresh_cm = 60; // >= 60cm = fully dim (0 = off)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  /* ----- read photo-resistor ----- */
  int lightVal = analogRead(lightPin); // 0 = bright 1023 = dark

  /* ----- read ultrasonic distance */
  // clear trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // whats that again

  // trigger pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // read echo
  duration = pulseIn(echoPin, HIGH, 30000); // timeout 30 ms ~ 5m
  // distance
  distance = duration * 0.034 / 2; // cm

  /* logic + fading */
  if (lightVal > darkTresh && distance <= farThresh_cm) {
    // map distance -> brightness (closer -> brighter)
    // distance <= nearTresh = 255, distance >= farThresh = 0
    int brightness = map(constrain(distance, nearTresh_cm, farThresh_cm), nearTresh_cm, farThresh_cm, 255, 0);
    analogWrite(ledPin, brightness);
  } else {
    analogWrite(redPin, 0); // off (too bright or too far away)
  }

  /* serial debug */
  Serial.print("Light: ");
  Serial.print(lightVal);
  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(50); // 50ms refresh (20Hz)

}
