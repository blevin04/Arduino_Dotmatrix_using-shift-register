int dataPin=8;
int latchPin=9;
int clockPin=10;

byte value=0;

void setup() {
  // put your setup code here, to run once:
pinMode(dataPin,OUTPUT);
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<8;i++){
bitSet(value,i);
updateShiftRegister();
  }

}
void updateShiftRegister(){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST, value);
  digitalWrite(latchPin,HIGH);
}