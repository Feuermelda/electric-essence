const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int potPin = A0;


void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  int potVal = analogRead(potPin); // 0-1023
  Serial.println(potVal);
  // Map to a delay between 2ms and 20ms
  int stepDelay = map(potVal, 0, 1023, 2, 20); // take the value potVal which lies somewhere between 0 and 1023 and convert it to a number between 2 and 20

  for (int i = 0; i < 768; i++) {
    setColor(i);
    delay(stepDelay); // adjust for speed ( 5-15ms feels great )
    Serial.println(potVal);
  }
}

void setColor(int pos) {
  int r, g, b;

  if (pos < 256) {
    r = 255 - pos;
    g = pos;
    b = 0;
  } else if (pos < 512) {
    pos -= 256;
    r = 0;
    g = 255 - pos;
    b = pos;
  } else {
    pos -= 512;
    r = pos;
    g = 0;
    b = 255 - pos;
  }

  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}
