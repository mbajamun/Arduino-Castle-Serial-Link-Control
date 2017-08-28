#include "SPI.h"
#include "CastleLink.h"
/*const int Mosipin = 11; 
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

void Speed_Cont(byte reg, short data) {
  digitalWrite(DataLink->getDataPin(3), LOW);
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
*/
//Setup Here
unsigned int pinID[4] = {11,12,13,10}; //Mosi, Miso, Sck, Nss
uint8_t devID = 0;
CastleLink castleLink(pinID, devID);
void setup() {
  SPI.beginTransaction(SPISettings(300000,MSBFIRST,SPI_MODE0));
  pinMode(castleLink.getDataPin(3),OUTPUT);
  SPI.begin(); 
  SPI.setBitOrder(MSBFIRST);
  castleLink.Clear_Cont();
}

void loop() {
  castleLink.Speed_Cont(128,65535);
}
