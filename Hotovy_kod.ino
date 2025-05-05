#include <Servo.h>
Servo servo;
int servoPin = 9;
int potPin= 2;
int angle = 0;
int LED1 = 11;
int LED2 = 12;
int LED3 = 13;
void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
  servo.write(0);
  pinMode(potPin,INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, LOW);

  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, LOW);

  pinMode(LED3, OUTPUT);
  digitalWrite(LED3, HIGH);
}

void loop() {
  int reading = digitalRead(potPin);

  if(reading == LOW){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);

    angle = angle +40;
    servo.write(angle);

    if(angle >= 180){
      angle = -40;
      digitalWrite(LED1, HIGH);
    }
    delay(3000);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
  }
}
