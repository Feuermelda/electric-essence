// ambient mood light with a twist
// rgb glows in rainbow color fade when its dark and no motion
// rgb glows bright red when there is motion detected in the dark - interrupts rainbow fade
// rgb glows yellow and blue when its bright and no motion
// rgb blinks green and orange when its bright and motion detected - interrupts yellow and blue

const int redPin = 6;
const int greenPin = 5;
const int bluePin = 11;

const int trigPin = 9;
const int echoPin = 10;

const int lightPin = A0;

long duration;
int distance;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read light value first
  int lightVal = analogRead(lightPin);
  Serial.print("Light: ");
  Serial.print(lightVal);
  
  // ultrasonic logic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;
  Serial.print(" | Distance: ");
  Serial.println(distance);

  if (lightVal <= 500) {
    if (distance <= 20) {
    analogWrite(redPin, 240);
    analogWrite(greenPin, 10);
    analogWrite(bluePin, 0);
    } else {
      for (int i = 0; i < 768; i++) {
        rainbow(i);
        delay(5);
      }
      }
  } else {
    if (distance <= 20) {
      for (int i = 0; i < 5; i++) {
        analogWrite(redPin, 245);
      analogWrite(greenPin, 123);
      analogWrite(bluePin, 24);
      delay(100);
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      delay(100);
      analogWrite(redPin, 68);
      analogWrite(greenPin, 245);
      analogWrite(bluePin, 24);
      delay(100);
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      delay(100);
      }
      
    } else {
      for (int i = 0; i < 512; i++) {
        blueyellowfade(i);
        delay(5);
      }
      
    }
  } 
}

bool isMotionDetected() {
  
}

void blueyellowfade(int pos) {
  int red, green, blue;
  
  if (pos < 256) {
    red = 255;
    green = 256 - pos;
    blue = pos;
  } else {
    pos -= 256;
    red = pos;
    green = 255;
    blue = 256 - pos;
  }
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void rainbow(int pos) {
  int red, green, blue;

    if (pos < 256) {
      red = 255 - pos;
      green = pos;
      blue = 0;
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
