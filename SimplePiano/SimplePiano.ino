const int buzzerPin = 10;
const int redLedPin = 13;
const int yellowLedPin = 12;
const int greenLedPin = 11;

const int buttonNoteCPin = 7;
const int buttonNoteDPin = 8;
const int buttonNoteEPin = 9;

const int noteC = 261; // Dó
const int noteD = 293; // Ré
const int noteE = 329; // Mi


void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  pinMode(buttonNoteCPin, INPUT_PULLUP);
  pinMode(buttonNoteDPin, INPUT_PULLUP);
  pinMode(buttonNoteEPin, INPUT_PULLUP);

}

void loop() {
  bool buttonNoteCState = digitalRead(buttonNoteCPin);
  bool buttonNoteDState = digitalRead(buttonNoteDPin);
  bool buttonNoteEState = digitalRead(buttonNoteEPin);

  if (buttonNoteCState == LOW) {
    tone(buzzerPin, noteC);
    digitalWrite(redLedPin, HIGH);
  }

  else if (buttonNoteDState == LOW) {
    tone(buzzerPin, noteD);
    digitalWrite(yellowLedPin, HIGH);
  }

  else if (buttonNoteEState == LOW) {
    tone(buzzerPin, noteE);
    digitalWrite(greenLedPin, HIGH);
  }
  else {
    noTone(buzzerPin);
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  }
}
