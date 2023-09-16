const int car_red = 13;
const int car_yellow = 12;
const int car_green = 11;

const int pedestrian_red = 9;
const int pedestrian_green = 10;

void setup() {
  pinMode(car_green,OUTPUT);
  pinMode(car_yellow,OUTPUT);
  pinMode(car_red,OUTPUT);
  
  pinMode(pedestrian_red,OUTPUT);
  pinMode(pedestrian_green,OUTPUT);
}

void loop() {
  carsStop();
  delay(500);                         // Add a delay between carsStop and pedestrianProceed to increase safety.
  pedestrianProceed();
  delay(3000);
  pedestrianAttention();

  pedestrianStop();
  delay(500);                         // Add a delay between pedestrianStop and carsProceed to increase safety.
  carsProceed();
  delay(3000);
  

  carsAttention();
  delay(2000);
}

void carsProceed() {
  digitalWrite(car_green, HIGH);
  digitalWrite(car_yellow, LOW);
  digitalWrite(car_red, LOW);
}

void carsAttention() {
  digitalWrite(car_green, LOW);
  digitalWrite(car_yellow, HIGH);
  digitalWrite(car_red, LOW);
}

void carsStop() {
  digitalWrite(car_green, LOW);
  digitalWrite(car_yellow, LOW);
  digitalWrite(car_red, HIGH);
}

void pedestrianStop() {
  digitalWrite(pedestrian_red, HIGH);
  digitalWrite(pedestrian_green, LOW);
}

void pedestrianProceed() {
  digitalWrite(pedestrian_red, LOW);
  digitalWrite(pedestrian_green, HIGH);
}

void pedestrianAttention() {
  digitalWrite(pedestrian_green, LOW);
  for(int i = 0; i < 3; i++) {
    digitalWrite(pedestrian_red, HIGH);
    delay(200);
    digitalWrite(pedestrian_red, LOW);
    delay(200);
   }
}
