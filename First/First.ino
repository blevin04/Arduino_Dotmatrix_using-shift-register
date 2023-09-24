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

void select(byte disp, int post, bool state){
byte base = 0b0000000000000001;
  switch (post) {
    case 0: if(disp & base){
      break;
    }else{
      disp = disp | base;
      
    }
    break;
    case 1: if(disp & base<<1){
      break;
    }else{
      disp = disp | base<<1;
    }
    case 2
  }
}