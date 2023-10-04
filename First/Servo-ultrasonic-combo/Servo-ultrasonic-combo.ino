#include <Servo.h>
#include <NewPing.h>
float distance,duration;
int iterations =12;
int trigPin=9;
int echoPin=10;
int maxDist=400;
Servo myServo;
NewPing Sonic1 (trigPin,echoPin,maxDist);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
