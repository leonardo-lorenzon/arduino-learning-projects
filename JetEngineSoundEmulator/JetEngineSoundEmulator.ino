int frequency = 100;
const int increasyFrequencyButtonPin = 11;
const int decreasyFrequencyButtonPin = 10;
const int buzzerPin = 9;

int maximumHumanHearingFrequency = 20000; // General maximum limit of human hearing range
int minimumHardwareFrequency = 31;        // It is not possible to generate tones lower than 31Hz. See https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(increasyFrequencyButtonPin, INPUT_PULLUP);
  pinMode(decreasyFrequencyButtonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(increasyFrequencyButtonPin) == LOW) {
      frequency += 10;

      if (frequency > maximumHumanHearingFrequency) {
          frequency = maximumHumanHearingFrequency;
        }
    }

  if (digitalRead(decreasyFrequencyButtonPin) == LOW) {
      frequency -= 10;

      if (frequency < minimumHardwareFrequency) {
          frequency = minimumHardwareFrequency;
        }
    }

  tone(buzzerPin, frequency);
  delay(20);
}
