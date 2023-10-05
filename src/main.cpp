#include <Arduino.h>

const int pwm = 3;
const int trigPin = 7;
const int echoPin = 8;
long microsecondsToCentimeters(long microseconds);

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pwm, OUTPUT); //3 = højre motor
}

void loop() {
  long duration, cm;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  if(cm < 30){
    //dreje til venstre (sænk farten på venstre motor)
    analogWrite(pwm, 155);

  } else{
    analogWrite(pwm, 255);
  }

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}