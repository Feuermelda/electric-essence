const int redPin = 9; // Pulse Width Modulation PWM pin for red channel
const int greenPin = 10;
const int bluePin = 11;
const int buttonPin = 2;

unsigned long previousMillis = 0; // remember5s last color-change time
const unsigned long interval = 1000; // 1s per color
int colorStep = 0; // 0 = red, 1 = green, 2 = blue

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  bool pressed = digitalRead(buttonPin) == LOW;

  if (pressed) { // if button is pressed -> show color sequence
    unsigned long now = millis();
    if (now - previousMillis >= interval) { // time to change color, has 1s passed?
    previousMillis = now; // save new time
    colorStep = (colorStep + 1) % 3; // 0->1->2->0

    }
    // turn on the current color (dimmed a bit = 100/255)
    analogWrite(redPin, (colorStep == 0) ? 100 : 0);
    analogWrite(greenPin, (colorStep == 1) ? 100 : 0);
    analogWrite(bluePin, (colorStep == 2) ? 100 : 0);
  } else {
    // button not pressed -> LED off, reset cycle
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    colorStep = 0; // start with red next time
    previousMillis = millis(); // avoid instant jump when pressed again
  }
}
