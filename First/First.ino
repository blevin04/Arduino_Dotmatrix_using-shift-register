int dataPin=8;
int latchPin=9;
int clockPin=10;

short val=0b0000000000000000;

void setup() {
  // put your setup code here, to run once:
pinMode(dataPin,OUTPUT);
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<16;i++){
    select(val,i,HIGH);
    shift(val);
    delay(250);
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

void select(short bit, int index, bool state){
short baseHigh = 0b0000000000000001;
short baseLow =0b1111111111111110;
  if(bit & baseHigh<<index){
     if(state){
      return bit;
     }else{
      short tempBit = baseLow<<index;
      short identity = tempBit | (~tempBit>>1);
      bit &= identity;
      return bit;
     }
    }else{
      if(state){
        bit |=  baseHigh<<index;
        return bit;
      }else{
        return bit;
      }
    }
}