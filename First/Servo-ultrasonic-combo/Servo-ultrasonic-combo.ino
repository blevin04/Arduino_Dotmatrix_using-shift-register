#include <Servo.h>
#include <NewPing.h>
float distance,duration;
int iterations =12;
int trigPin=10;
int echoPin=9;
int maxDist=400;
int servoPin=8;
int distArray[180/5];
Servo myServo;
NewPing Sonic1 (trigPin,echoPin,maxDist);
void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 for(int i=0;i<=180;i+=5){
  myServo.write(i);
  duration=Sonic1.ping_median(iterations);
  distance =(duration/2)*0.0341;
  distArray[i]=distance;
  Serial.print(distArray[i]);
  Serial.println("cm");
  delay (120);
 }
 for(int i=180;i>=0;i-=5){
  myServo.write(i);
  duration=Sonic1.ping_median(iterations);
  distance =(duration/2)*0.0341;
  distArray[i]=distance;
  Serial.print(distArray[i]);
  Serial.println("cm");
  delay (120);
 }
}
