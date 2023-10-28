const int potenciometerPin = A0;
const int ledPin = 11;
int reading = 0;
int pwm = 0;

void setup() { 
  pinMode(potenciometerPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  reading = analogRead(potenciometerPin);

  pwm = map(reading, 0, 1023, 0, 255);

  analogWrite(ledPin, pwm);
}
