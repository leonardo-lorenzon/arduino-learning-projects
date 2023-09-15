int buttonInterruptPin = 9;
int whiteLedPin = 12;
int greenLedPin = 11;

void setup() {
  pinMode(buttonInterruptPin, INPUT);
  pinMode(whiteLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

}

void loop() {
  if (digitalRead(buttonInterruptPin) == HIGH) {
      digitalWrite(whiteLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
    }
  else {
      digitalWrite(whiteLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
    }

}
