#include <Servo.h>
#include <NewPing.h>
#include <DHT.h>
#define type DHT11 
float distance,duration;
int iterations =12;
int trigPin=10;
int echoPin=9;
int maxDist=400;
int servoPin=8;
int dhtPin=11;
int distArray[180/5];
Servo myServo;
DHT HT(dhtPin,type);
float tempC,humidity;
float c ;
NewPing Sonic1 (trigPin,echoPin,maxDist);
void setup() {
  // put your setup code here, to run once:
  HT.begin();
  myServo.attach(servoPin);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 for(int i=0;i<=180;i+=5){
  myServo.write(i);
  duration=Sonic1.ping_median(iterations);
    tempC=HT.readTemperature();
  humidity =HT.readHumidity();
  c=331.4+(0.606*tempC)+(0.0124*humidity);
  distance =((duration/20)*c)/1000;
  distArray[i]=distance;
  Serial.print(distArray[i]);
  Serial.println("cm");
  Serial.print("Temp=");
  Serial.print(tempC);
  Serial.println("*C");
 
  Serial.print ("humidity=");
   Serial.println(humidity);
  delay (120);
 }
 for(int i=180;i>=0;i-=5){
  myServo.write(i);
  duration=Sonic1.ping_median(iterations);
  tempC=HT.readTemperature();
  humidity =HT.readHumidity();
  c=331.4+(0.606*tempC)+(0.0124*humidity);
  distance =((duration/20 )*c)/1000 ;
  distArray[i]=distance;
  Serial.print(distArray[i]);
  Serial.println("cm");
  Serial.print("Temp=");
  Serial.print(tempC);
  Serial.println("*C");
  Serial.print ("humidity=");
  Serial.println(humidity);
  delay (120);
 }
}
