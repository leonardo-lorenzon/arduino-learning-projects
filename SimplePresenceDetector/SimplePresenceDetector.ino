const int ldrPin = A0;
const int buttonPin = 8;
const int buzzerPin = 9;
bool isPresenceDetected = 0;
bool isButtonPressed = false;

void setup() {
  Serial.begin(9600);
  
  pinMode(ldrPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  isPresenceDetected = presenceDetected(ldrPin);

  isButtonPressed = buttonPressed(buttonPin);

  if (isPresenceDetected) {
    ringAlarm(buzzerPin);
  } 
  else if (isButtonPressed) {
    silenceAlarm(buzzerPin);
  }

  delay(100);
}

bool presenceDetected(int ldrPin) {
  return analogRead(ldrPin) < 900;
}

bool buttonPressed(int buttonPin) {
  return digitalRead(buttonPin) == LOW;
}

void ringAlarm(int buzzerPin) {
  tone(buzzerPin, 1000);
}

void silenceAlarm(int buzzerPin) {
  noTone(buzzerPin); 
}
