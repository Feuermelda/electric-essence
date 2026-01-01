const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int buttonPin = 2;
const int potPin = A0;

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}


void loop() {
  for (int i = 0; i < 768; i++) { // for full smooth rainbow cycle split into 3 color phases: Red->Green (256 steps) Green -> Blue (256 steps), Blue -> Red (256 steps)
    setColor(i);
    delay(5); // adjust for speed ( 5-15ms feels great )
  }
}

void setColor(int pos) {
  int red, green, blue;

  if (pos < 256) {
    red = 255 - pos; // red fades out
    green = pos; // green fades in
    blue = 0; // no blue needed
  } else if (pos < 512) {
    pos -= 256;
    red = 0;
    green = 255 - pos;
    blue = pos;
  } else {
    pos -= 512;
    red = pos;
    green = 0;
    blue = 255 - pos;
  }

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
