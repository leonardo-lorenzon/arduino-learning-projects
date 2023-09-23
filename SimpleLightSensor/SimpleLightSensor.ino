const int ldrPin = A0;
const int ledPin = 8;
int reading = 0;

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  reading = analogRead(ldrPin);

  if (reading < 500) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}
