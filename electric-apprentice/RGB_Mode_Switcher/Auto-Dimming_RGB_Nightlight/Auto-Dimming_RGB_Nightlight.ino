const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int lightPin = A0;

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  
    
    int lightVal = analogRead(lightPin); // 0 (bright) to 1023 (dark)
    int brightness = map(lightVal, 0, 1023, 10, 150); // no invert + scale
    analogWrite(redPin, brightness);
    analogWrite(greenPin, 20);
    analogWrite(bluePin, 0);
    delay(50);
    Serial.println(lightVal);
    
}
