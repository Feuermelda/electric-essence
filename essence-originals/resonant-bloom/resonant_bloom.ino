const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

const int lightPin = A0;
const int soundPin = A3;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   int lightVal = analogRead(lightPin); // darkness 0-1023
    int soundVal = analogRead(soundPin); // sound 0-1023

    Serial.print("Light: ");
    Serial.print(lightVal);
    Serial.print(" | Sound: ");
    Serial.println(soundVal);

    if (lightVal < 500) {
      if (soundVal > 85) {
        int brightness = map(soundVal, 86, 1023, 10, 255);
        analogWrite(redPin, brightness);
        analogWrite(greenPin, brightness / 10);
        analogWrite(bluePin, 0);
      }
    } else {
      // turn off RGB
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
    }

    delay(100);
  }
