const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

int mode = 0; // 0 = OFF, 1 = solid red, 2 = rainbow
int buttonState;
int lastButtonState = HIGH;


void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop() {
  buttonState = digitalRead(buttonPin);

  // detect rising edge (press)
  if (buttonState == LOW && lastButtonState == HIGH) { // only one press per click no auto-repeat. 
    mode++; // advance to next mode
    if (mode > 2) mode = 0; // wrap
    delay(200); // debounce
  }
  lastButtonState = buttonState;

  switch (mode) {
    case 0: // OFF
    setColor(0, 0, 0);
    break;

    case 1: // solid warm red
    setColor(150, 20, 0);
    break;

    case 2: // Rainbow fade
    rainbowFade();
    break;
  }
}

// function to set color using PWM
void setColor(int r, int g, int b) { // gives direct PWM brightness (0 -255) to each channel
  
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void rainbowFade() {
  static int i = 0; // lets the rainbow keep flowing even though the function is called repeatedly, cause of static it remembers it position
  i = (i + 1) % 768; // loop from 0 to 767

  int r, g, b;
  if (i < 256) {
    r = 255 - i;
    g = i;
    b = 0;
  } else if (i < 512) {
    r = 0;
    g = 511 - i;
    b = i - 256;
  } else {
    r = i - 512;
    g = 0;
    b = 767 - i;
  }

  setColor(r / 5, g / 5, b / 5); // dim a bit
  delay(10);
}
