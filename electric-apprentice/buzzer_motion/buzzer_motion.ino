const int pirPin = 2; // PIR sensor signal pin
const int ledPin = 13; // LED output
const int buzzerPin = 8; // Buzzer output
// const helps prevent accidental changes and lets the compiler optimize better. Also makes the code more readable and easier to update.

void setup() { // void no return value, setup only runs once on startup or reset
  pinMode(pirPin, INPUT); // pinMode tells Arduino how to treat each pin, INPUT for things Arduino reads from, and OUTPUT things that Arduino controls
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // start serial Monitor, opens a communication channel with your computers Serial Monitor, 9600 is a standard, Arduino and Serial Monitor will communicate at 9600 bits per sec
  // fast enough for most sensor data and reliable across many boards. 
  // Fun fact: higher baud rates like 115200 exist and are faster, but sometimes cause noise or syncing problems on older boards or cables.

}

void loop() { 
  int motion = digitalRead(pirPin);
  Serial.println(motion); // See what the PIR is doing

  if (motion == HIGH) {
    Serial.println("Motion Detected!");
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    // replace delay with millis cause it doesnt pause the whole program, better for multitasking
  }

  delay(100); // Small delay to stabilize reading
}
