#include "SPI.h"
const int Mosipin = 11; 
const int Misopin = 12;
const int sckpin = 13;
const int nsspin = 10; 
const int ID_const = 0;

void Clear_Cont(){
  digitalWrite(nsspin, LOW);
  for(int i = 0; i < 5; ++i){
    SPI.transfer(0);
  }
  digitalWrite(nsspin, HIGH);
  return;
}

//Setup Here
void setup() {
  pinMode(nsspin,OUTPUT);
  SPI.begin(); 
  SPI.setBitOrder(MSBFIRST);
  Clear_Cont();
}

void Speed_Cont(byte reg, short data) {
  digitalWrite(nsspin, LOW);
  byte byte0 = ID_const >> 1;
  byte0++;
  SPI.transfer(byte0);
  //SPI.transfer(1);
  SPI.transfer(reg);
  SPI.transfer(data);
  int checksum = 0-(byte0 + reg + highByte(data) + lowByte(data));
  SPI.transfer(checksum);
  digitalWrite(nsspin,HIGH);  
  return;
}

void loop() {
  Speed_Cont(128,32000);
}
