#include <Servo.h> 

const int trigPin = 9;
const int echiPin = 10;
const int buzzerPin = 3;

int distanceCm;
long durartion;

void setup(){
  Serial.begim(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(buzzer, OUTPUT);

}
void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  dealyMicroseconds(10);
  digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH)
distanceCm = 0.034/2;

Serial.print("distancia: ");
Serial.print(distanceCm);
Serial.print("cm");

if (distanceCm > 0 && distanceCm < 50) {
  digitalWrite(buzzerPIn, HIGH);
}
else
{
  digitalWrite(trigPin, LOW);
}
delay(100);
}