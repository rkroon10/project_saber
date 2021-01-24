#include <Servo.h>;
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
const int TriggerPin = 12;
const int EchoPin2 = 10;
const int EchoPin = 11;
const int motorSignalPin = 5; //Left Servo
const int motorSignalPin2 = 6; //Right Servo

Servo ServoL;
Servo ServoR;

void setup(void)

{ 
pinMode(TriggerPin, OUTPUT);

pinMode(EchoPin, INPUT);

ServoL.attach(motorSignalPin);
ServoR.attach(motorSignalPin2);

Serial.begin(9600);

}

void loop(void)

{



//Front Ultra detection
digitalWrite(TriggerPin, HIGH);

delayMicroseconds(10);

digitalWrite(TriggerPin, LOW);

long duration = pulseIn(EchoPin, HIGH);

float distance = duration * 0.017F;

delay(100);
Serial.print("Distance Front: ");
Serial.print(distance);
Serial.print(" | ");

if(distance < 10)
{
//stop
ServoL.write(90);
ServoR.write(90);
delay(1000);

//back up
ServoL.write(0);
ServoR.write(180);
delay(500);

//turn
ServoL.write(0);

ServoR.write(0);
delay(1000);

delay(10);
}
else
{
  ServoL.write(180);
  ServoR.write(0);
 }

//Rear Ultra
digitalWrite(TriggerPin, HIGH);

delayMicroseconds(10);

digitalWrite(TriggerPin, LOW);

long duration2 = pulseIn(EchoPin2, HIGH);

float distance2 = duration2 * 0.017F;

delay(100);
Serial.print("Distance Rear: ");
Serial.print(distance2);
Serial.println(" ");




}
