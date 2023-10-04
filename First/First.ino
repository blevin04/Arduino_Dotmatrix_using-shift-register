int dataPin=8;
int latchPin=9;
int clockPin=10;
short output;
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
    select(output,i,HIGH);
    shift(output);
    Serial.print(output,BIN);
    delay(150);
  }
  
   for(int i=15;i>=0;i--){
    select(output,i,LOW);
    shift(output);
    Serial.print(output,BIN);
    delay(150);
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

short select(short bit, int index, bool state){
short baseHigh = 0b0000000000000001;
short baseLow =0b1111111111111110;
  if(bit & baseHigh<<index){
     if(state){
       output=bit;
      return output;
     }else{
      short tempBit = baseLow<<index;
      short identity = tempBit | (~tempBit>>1);
      bit &= identity;
       output=bit;
      return output;
     }
    }else{
      if(state){
        bit |=  baseHigh<<index;
        output=bit;
        return output;
      }else{
        output=bit;
        return output;
      }
    }
}