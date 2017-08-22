#include "SPI.h"
int Mosipin = 11; 
 int Misopin = 12;
int sckpin = 13;
int nsspin = 10; 

void setup() {
  pinMode(nsspin,OUTPUT);
  SPI.begin(); 
SPI.setBitOrder(MSBFIRST);
}

void loop() {
  digitalWrite(nsspin, LOW);
  SPI.transfer(0);
  SPI.transfer(
  

}
