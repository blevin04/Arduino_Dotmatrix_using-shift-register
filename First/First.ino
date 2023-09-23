int dataPin=8;
int latchPin=9;
int clockPin=10;

int value[16];

void setup() {
  // put your setup code here, to run once:
pinMode(dataPin,OUTPUT);
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<16;i++){
    
  }

}


void shift(int pin) {
  digitalWrite(latchPin, LOW);

  // shift the bits out:
  shiftOut(dataPin, clockPin,MSBFIRST, pin>>8);
  shiftOut(dataPin, clockPin,MSBFIRST, pin);
  // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);
  delay(100);
}